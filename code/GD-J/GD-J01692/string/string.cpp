#include <bits/stdc++.h>
using namespace std;
struct node{
	long long count;
	char data;
}a[200005];
int n,x,siz;
long long ans; 
char y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for( int i = 1;i<=n;i++ ){
		cin >> x >> y;
		if( y == a[siz].data ){
			a[siz].count += x;
		}
		else{
			siz ++;
			a[siz].count = x;
			a[siz].data = y;
		}
	}
	int l = 1,r = siz;
	while( l <= r ){
		long long xxx = a[l].count,yyy = a[r].count;
		long long mincnt = min(xxx,yyy);
		if( a[l].data != a[r].data ){
			ans += mincnt;
		}
		if( xxx == yyy ){
			l++;
			r--;
			continue;
		}
		if( xxx < yyy ){
			l++;
			a[r].count -= xxx;
		}
		else{
			r--;
			a[l].count -= yyy;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
