#include <bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long n,m; 
long long a[M];
long long ans;
int an(int x,int y){
	string s,ss;
	while(x>0){
		if(x%2==1) s+='1';
		else s+='0';
		x/=2;
	}
	while(y>0){
		if(y%2==1) ss+='1';
		else ss+='0';
		y/=2;
	}
	int l=s.size();
	int ll=ss.size();
	if(l>ll) for(int i=ll-1;i<l;i++) ss+='0';
	else for(int i=l-1;i<ll;++i) s+='0';
	string sc;
	for(int i=0;i<max(l,ll);++i){
		if(s[i]=='1'&&ss[i]=='1') sc+='1';
		else sc+='0';
	}
	int lc=sc.size();
	int c=1;
	int num=0;
	for(int i=0;i<lc;++i){
		if(sc[i]=='1') num+=c;
		c*=2;
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>n-m;--i){
		ans=an(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
