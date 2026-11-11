#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ans,x=1,s[200010],p=1,d[200010],f[200010],o,w;
bool b[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=30;i++)
	x*=2;
	for(int i=1;i<=n;i++){
	cin>>a[i];
}sort(a+1,a+1+n);
while(a[n]<x){
	x/=2;
}s[1]=1;
while(s[p]<=x){
	s[++p]=s[p-1]*2;
}if(x==0)
p=0,s[1]=0;
	for(int i=p;i>=1;i--){
		int sum=0;
		for(int j=n;j>=1;j--){
			if(a[j]>=s[i]&&b[j]==0)
			sum++;
		}if(sum>=m){
			ans+=s[i];
			for(int j=n;j>=1;j--){
				if(a[j]<s[i]&&b[j]==0)
				b[j]=1;
				else if(a[j]>=s[i]&&b[j]==0)
				a[j]-=s[i];
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[j]>=s[i]&&b[j]==0)
				a[j]-=s[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
