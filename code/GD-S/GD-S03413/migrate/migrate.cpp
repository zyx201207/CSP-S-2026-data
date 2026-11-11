#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T,n,s;
ll d;
vector<ll> g;
ll in(){
	ll f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
int dm(){
	int x=0,t,s=0;
	while(x<n-1){
		t=x+1;
		while(t<n-1&&g[t]-g[x]<=d)
			++t;
		if(t>=n-1&&g[t]-g[x]<=d)
			return s+1;
		++s;
		x=t-1;
	}
	return s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n;d=in();
		for(int i=0;i<n;++i)
			g.push_back(in());
		int s=dm();
		cout<<s<<endl;
		g.clear();
	}
	return 0;
}
