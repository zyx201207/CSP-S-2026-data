#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	char c;
	int len,l,r;
}a[200005],goal[200005];
int n,L,tmp,ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i){
		scanf("%lld %c",&a[i].len,&a[i].c);
		L += a[i].len;
		a[i].l = L - a[i].len + 1,a[i].r = L;
	}
	int mid = L / 2 + 1;
//	cout << mid << "\n"; 
	for(int i = 1;i <= n;++i){
		if(L % 2 == 1)
			if(a[i].r >= mid && a[i].l <= mid){
				if(mid - 1 >= a[i].l) goal[++tmp] = {a[i].c,mid - a[i].l,a[i].l,mid - 1};
				goal[++tmp] = {a[i].c,1,mid,mid};
				if(a[i].r >= mid + 1) goal[++tmp] = {a[i].c,a[i].r - mid,mid + 1,a[i].r};
			}
			else goal[++tmp] = a[i];
		else
			if(a[i].r >= mid && a[i].l <= mid - 1){
				goal[++tmp] = {a[i].c,mid - a[i].l,a[i].l,mid - 1};
				goal[++tmp] = {a[i].c,a[i].r - mid + 1,mid,a[i].r};
			}
			else goal[++tmp] = a[i];
			
	}
//	for(int i = 1;i <= tmp;++i)
//		cout << goal[i].l << " : " << goal[i].r << "\n";
	int x = 1,y = 1,l = 1,r = n;
	while(l < r){
//		cout << l << " " << x << " : " << r << " " << y << "\n";
		int ta = x,tb = y;
		if(a[l].c != a[r].c) ans += min((a[r].len - tb + 1),(a[l].len - ta + 1));
		x += (a[r].len - tb + 1),y += (a[l].len - ta + 1);
		if(x > a[l].len) l++,x = 1;
		if(y > a[r].len) r--,y = 1;
	}
	printf("%lld\n",ans);
    return 0;
}
/*
L = 5;
5
2 a
2 b
1 d
1 b
3 c

1d : 1d
1  : 1
ans = 2;

***(**||*)****
*/
