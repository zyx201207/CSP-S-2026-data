#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[200005][32],cnt[32];
long long ans;
void get_two(int i){
	int sum=0;
	while(x!=0){
		sum++;
		a[i][sum]=x%2;
		cnt[sum]+=x%2;
		x/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		get_two(i);
	}
	for(int i=31;i>=1;i--){
		if(cnt[i]>=m){
			ans+=pow(2,i-1);
			for(int j=1;j<=n;j++){
				if(a[j][i]!=1){
					for(int k=31;k>=1;k--){
						cnt[k]-=a[j][k];
						a[j][k]=0;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
