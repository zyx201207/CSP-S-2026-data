#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%d",a+i);
	int r = n;
	int ans = 0;
	for(int i = 29;i >= 0;i--){
		int x = 1,y = r;
		while(x < y){
			while(x < y && (a[x] & (1 << i)))++x;	
			while(x < y && !(a[y] & (1 << i)))--y;
			if(x >= y)break;
			swap(a[x],a[y]);
			++x,--y;
		}
		x = 0;
		while(x < r && (a[x+1] & (1 << i)))++x;
		if(x >= m){
			ans |= 1 << i;
			r = x;
		}
	}
	printf("%d",ans);
}
