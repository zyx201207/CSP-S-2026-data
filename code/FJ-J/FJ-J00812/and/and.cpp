#include<bits/stdc++.h>
using namespace std;
long long x,sum;
int n,m,MAX=0,b[35],z;
bool a[200005][35],s[35],c[200005];
int check(long long k,int i){
	int j=0;
	while(k){
		if(k%2==1){
			a[i][j]=1;
			b[j]++;
		}
		k/=2;
		j++;
	}
	return j--;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		MAX=max(MAX,check(x,i));
	}
	for(int i=MAX;i>=0;i--){
		if(b[i]>=m){
			if(z==0){
				z=i;
			}
			s[i]=1;
			for(int j=1;j<=n;j++){
				if(c[j]==1){
					continue;
				}else{
					if(a[j][i]==0){
						c[j]=1;
						for(int k=0;k<=i;k++){
							if(a[j][k]==1){
								b[k]--;
							}
						}
					}
				}
			}
		}
	}
	for(long long i=0,j=1;i<=z;i++){
		if(s[i]==1){
			sum+=j;
		}
		j*=2;
	}
	cout<<sum;
	return 0;
} 
