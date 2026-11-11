#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+100;
struct node{
	long long a,id;
	char c;
}a[maxn];
long long pos[maxn];
long long ans = 0;
long long b[maxn];
bool cmp(node a,node b){
	return a.a<b.a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		a[i].id = 1;
		b[i] = a[i].a;
		a[i].a+=a[i-1].a;
	} 
	int tot = n;
	for(int i = n;i>=1;i--){
		b[i]+=b[i+1];
		a[++tot].a = b[i];
		a[tot].c = a[i].c;
		a[tot].id = 2;
	}
	n = tot;
	sort(a+1,a+1+n,cmp);
	long long x = n,y = n;
	for(int i = n;i>=1;i--){
		if(a[i].id == 1)pos[i] = y,x = i;
		else pos[i] = x,y = i;
		ans+=(a[i].a-a[i-1].a)*(a[pos[i]].c != a[i].c); 
	}
	cout<<ans/2;
	return 0;
}
/*
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%% 
*/ 
