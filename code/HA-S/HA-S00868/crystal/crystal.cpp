#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500010];
long long input(){
	long long l = 0 , c = 1;
	char b = 'a';
	while ( b < '0' || b > '9' )
	{
		if ( b == '-' )
			c = -1;
		b = getchar();
	}
	while ( b <= '9' && b >= '0' )
	{
		l = l * 10 + b - '0';
		b = getchar();
	}
	return l * c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = input();
	m = input();
	for ( int i = 1 ; i <= n ; i ++ )
		a[i] = input();
	sort(a+1,a+1+n);
	long long ans = 1 , l = 1 , s = 0;
	for ( int i = 2 ; i <= n ; i ++ )
	{
		s += ( i - l ) * ( a[i] - a[i-1] );
		while ( s > m )
			s -= ( a[i] - a[l++] );
		ans = max(ans,i-l+1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
