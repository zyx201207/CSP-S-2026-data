#include <bits/stdc++.h>
using namespace std;
const int MAXN =2*1e5+5;
string s,x;
long long n,cnt,l,r;
struct T{
	long long w;
	string x;
}a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	l=1;r=n;
	for(int i=1;i<=n;i++){
		cin >> a[i].w >> a[i].x;
	}
	while(l!=r){
		if(a[l].x!=a[r].x){
			cnt+=min(a[l].w,a[r].w);
			a[l].w-=min(a[l].w,a[r].w);
			a[r].w-=min(a[l].w,a[r].w);
			if(a[l].w==0)l++;
			if(a[r].w==0)r--;
		}
	}
	cout << cnt;
}
