#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
struct node{
	int l,r;
}a[MAXN];
int n,m;
bool cmp(node a,node b){
	if(a.l == b.l) return a.r<b.r;
	else return a.l<b.l;
}
int maxn = 0;
bool c[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int b;
		cin>>b;
		a[i].l = b;
		a[i].r = b+m;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		int cnt = 0;
		for(int j = 1;j<=n;j++){
			if(a[i].r>=a[j].l&&a[i].r<=a[j].r){
				cnt++;
			}
		}
		maxn = max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
} 
