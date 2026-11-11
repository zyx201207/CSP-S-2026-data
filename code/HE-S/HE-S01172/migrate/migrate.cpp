#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000010],f[2000010],t[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _,T,n;
	ll d;
	cin>>_>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n>5000){
			cout<<"0\n";
			continue;
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[j]=t[j]=0;
			int x=i,y=i;
			ll s=1;
			f[i]=t[i]=1;
			for(int j=i+1;j<=n;j++){
				while(x<=j&&a[j]-a[x]>d)s-=f[x],x++;
				if(y<x)y=x,s=f[x];
				while(y<j&&t[y+1]==t[x])y++,s+=f[y];
				f[j]=s,t[j]=t[x]+1;
//				if(i==1)cout<<x<<" "<<y<<" "<<j<<"\n";
//				cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<s<<" "<<f[j]<<"\n";
				if(f[j]==2)ans++;
//				if(f[j]>2)break;
			}
//			for(int j=1;j<=n;j++)cout<<f[j]<<" ";
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
