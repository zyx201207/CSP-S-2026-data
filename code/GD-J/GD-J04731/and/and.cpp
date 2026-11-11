#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll s,c,d;
}a[N];
ll n,m,ans;
void get(int p){
	ll x=a[p].s;
	while(x){
		a[p].c++;
		if(x&1) a[p].d++;
		else a[p].d=0;
		x>>=1;
	}
}
bool cmp(node n1,node n2){
	return n1.c==n2.c?n1.d>n2.d:n1.c>n2.c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		get(i);
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].s;
	for(int i=1,t;i<=n;i++){
		if(a[i].c!=a[i-1].c) t=0;	
		t++;
		if(t==m){
			ans=a[i-m+1].s;
			for(int j=i-m+2;j<=i;j++)
			    ans&=a[j].s;
			    break;
		}
	}
	if(!ans){
		ans=a[1].s;
		for(int i=2;i<=m;i++)
		     ans&=a[i].s;
	}
	cout<<ans;
	return 0;
} 
