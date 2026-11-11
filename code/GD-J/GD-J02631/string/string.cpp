#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2*1e5+5;

ll n,a[N],ans;
ll sf[N],sr[N],f,r;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin >> n;
	for(ll i=1;i<=n;i++) cin >> a[i] >> c[i];
	//前缀和,后缀和 
	for(ll i=1;i<=n;i++)
		sf[i] = sf[i-1] + a[i];
	for(int i=1;i<=n;i++)
		if(sf[i] >= sf[n]/2+sf[n]%2){
			n++;
			for(int j=n;j>i;j--) a[j] = a[j-1];
			for(int j=n;j>i;j--) c[j] = c[j-1]; 
			a[i] --;
			a[i+1] = 1;
			
			//cout << "!\n";
			//for(int j=1;j<=n;j++) printf("%d %c\n",a[j],c[j]);
			break;
		}
	for(ll i=1;i<=n;i++)
		sf[i] = sf[i-1] + a[i];
	sr[n+1] = 0;
	for(ll i=n;i;i--)
		sr[i] = sr[i+1] + a[i];
	//双指针 
	f = 1, r = n;
	ll A = a[1], B = a[n];
	ll l = sf[n],fre = 0;
	while(sf[f] <= l/2+l%2 && sr[r] <= l/2+l%2){
		//cout << f << ' ' << r << endl;
		//cout << A << ' ' << B << endl;
		if(c[f] != c[r]){
			fre = min(A,B);
			ans += fre;
			A -= fre, B -= fre;
			//cout << fre << endl;
		}else A = B = 0;
		
		if(A > B) r--, B += a[r];
		else if(A < B) f++, A += a[f];
		else f++,A += a[f] , r--,B += a[r];
	}
	
	cout << ans;
}
/*
9
5 e
3 a
2 d
4 b
5 e
2 b
5 a
2 b
4 b
eeeeeaaaddbbbbee|eeebbaaaaabbbbbb
eeeeeaddbb|eaaabbbbbb
f = 1	c[f] = a	r = 3	c[r] = c	ans = 1;
	1		   a		2		   b		  2

if(c[f] != c[r])
	ans += |sf[f]-sr[r]|
	
3 2
2
minA,b
(3-2) 2
minA-fre,B
*/

/*

	
*/
