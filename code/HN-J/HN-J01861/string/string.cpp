#include<bits/stdc++.h>
using namespace std;
long long n,a[200005][3],sum=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1][1]>>c;
	a[1][2]=c-'a';
	for(int i=2;i<=n;i++){
		cin>>a[i][1]>>c;
		a[i][2]=c-'a';
		if(a[i-1][2]==a[i][2]){
			a[i-1][1]+=a[i][1];
			i--;
			n--;
		}
	}

	for(int i=1,j=n;i<j;i++,j--){
		if(a[i][1]>a[j][1]){
			if(a[i][2]!=a[j][2]){
				sum+=a[i][1];
			}
			else{
				sum+=a[j][1];
			}
			if(a[j-1][2]==a[i][2]){
				a[j-1][1]-=a[i][1]-a[j][1];
				sum-=a[i][1]-a[j][1];
			}
			else a[i+1][1]+=a[i][1]-a[j][1];
		}
		if(a[i][1]<a[j][1]){
			if(a[i][2]!=a[j][2]){
				sum+=a[j][1];
			}
			else{
				sum+=a[i][1];
			}
			if(a[i+1][2]==a[j][2]) a[i+1][1]-=a[j][1]-a[i][1];
			else a[j-1][1]+=a[j][1]-a[i][1];
		}
		if(a[i][1]==a[j][1]){
			if(a[i][2]!=a[j][2]){
				sum+=a[i][1];
			}
		}
	}
	cout<<sum;
	return 0;
}
