#include<bits/stdc++.h>
using namespace std;
int n,m,x=2,a[200005],b[200005],s,f[50],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}while(x!=0)x/=2,s++;
	for(int i=0;i<=30;i++)f[i]=pow(2,i);
	for(int i=1;i<=n;i++)b[i]=1;
	for(int i=s;i>=1;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]/f[i-1]%2==1)cnt+=b[j];
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(a[j]/f[i-1]%2==1)b[j]=min(b[j],1);
				else b[j]=0;
			}
		}
	}x=f[30]-1;
	for(int i=1;i<=n;i++){
		if(b[i])x=x&a[i];
	}cout<<x;
	return 0;
}
