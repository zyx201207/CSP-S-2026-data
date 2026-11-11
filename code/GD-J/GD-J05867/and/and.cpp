#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxx,k;
struct Node
{
	ll x,l;
}a[200005];
bool cmp(Node a,Node b){
	if(a.l==b.l) return a.x>b.x;
	return a.l>b.l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		k=0;
		for(int j=a[i].x;j>0;j=j/2)
			k++;
		a[i].l=k;
	}
	if(n==3&&m!=1){
		if(m==2){
			cout<<max(max(a[1].x&a[2].x,a[2].x&a[3].x),a[1].x&a[3].x);
		}
		if(m==3) cout<<(a[1].x&a[2].x&a[3].x);
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1].x;
		return 0;
	}
	maxx=a[1].x;
	for(int i=2;i<=m;i++){
		maxx=a[i].x&maxx;
	}
	cout<<maxx;
	
	return 0;
} 
