#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long a,l,r;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	cin >> n;
	int l=1,r=n;
	long long nw=0,lt,sm=1,ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i].a >> a[i].c;
		a[i].l=sm;
		sm+=a[i].a;
		a[i].r=sm-1;
	}
	while(l<=r){
		lt=nw+1;
		nw=min(a[l].r,sm-a[r].l);
		if(a[l].c!=a[r].c) ans+=nw-lt+1;
		while(nw>=sm-a[r].l) r--;
	}
	cout << ans;
	return 0;
}
// 100·Ö 
