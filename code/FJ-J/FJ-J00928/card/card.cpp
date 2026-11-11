#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

const int N=5e5+5,M=3e5+5;

int n,k;
bool t[M];

struct node{
	int x,l,pos;
}a[N];

inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<=b.x;
	else return a.l<=b.l;
} 

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast;
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i].x,a[i].pos=i;
	t[0]=1;
	for(int i=n;i>=1;--i){
		if(t[a[i].x]){
			a[i].l=-1;
			continue;
		}
		t[a[i].x]=1;
		int p;
		for(p=i-1;p>=0;--p)
			if(t[a[p].x]) break;
		a[i].l=p+1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		cerr<<i<<": "<<a[i].x<<' '<<a[i].l<<'\n';
	}
	for(int i=1;i<=n;++i){
		if(a[i].l!=-1) cout<<a[i].pos-a[i].l+1<<' ';
	}
	//cout<<ans;
	return 0;
}

