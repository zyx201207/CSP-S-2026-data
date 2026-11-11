#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c,d,ans=1,e,f,g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(a[i]+j==a[i+1+e]){
				f=c;
				c++;
			}
			if(c-f==1) e++;
		}
		b[i]=c;
		c=0;
		e=0;
	}
	for(int i=1;i<=n;++i){
		c=max(b[i],c);
	}
	for(int i=1;i<=n;++i){
		if(b[i]==c){
			d=i;
			break;
		}
	} 
	for(int i=d+c;i>=d;--i){
		if(a[i]==a[i-1]) ans++;
		else{
			m-=a[i]-a[i-1];
			a[i-1]-a[i];
			if(m>=0) ans++;
			if(m<0&&a[i]==a[i-1]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
