#include<bits/stdc++.h>
#define endl '\n'
#define int unsigned long long
using namespace std;
int n,m,ans;
struct xh{
	int a,qlone,sz;
	string s;
}g[10005];
string fenjie(int x){
	string s;
	while(x>0){
		s+=to_string(x%2);
		x/=2;
	}
	return s;
}
int qlo(string s){
	int sz=s.size();
	int i=sz-1;
	while(s[i]=='1'){
		i--;
	}
	return sz-i-1;
}
bool cmp(xh x,xh y){
	if(x.qlone!=y.qlone){
		return x.qlone>y.qlone;
	}else{
		return x.sz>y.sz;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i].a;
		g[i].s=fenjie(g[i].a);
		g[i].qlone=qlo(g[i].s);
		g[i].sz=g[i].s.size();
		//cout<<g[i].s<<' '<<g[i].qlone<<endl;
	}
	sort(g+1,g+1+n,cmp);
	ans=g[1].a;
	for(int i=2;i<=m;i++){
		ans=ans&g[i].a;
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12


5 3
31 3 1 15 7

*/
