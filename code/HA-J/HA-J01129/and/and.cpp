#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ff[200005];
struct node{
	int a,af;
}s[200005];
int f(ll a,int fa){
	if(a==0)return fa;
	fa+=(a%2);
	a/=2; 
	return f(a,fa);
}
bool cmp(node x,node y){
	if(x.af==y.af)return x.a>y.a;
	return x.af>y.af;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i].a;
		s[i].af=f(s[i].a,0);
	}
	sort(s+1,s+n+1,cmp);
	int a1=s[1].a;
	if(m==1)cout<<a1;
	else {
		for(int i=2;i<=m;i++)a1&=s[i].a;
		cout<<a1;
	}
}
