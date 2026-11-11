#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum,sum1,sum2,ans,len;
int n,l,r;
LL x,p,pp;char y;
string s,s1,s2;

struct{
	LL a;char c;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> x >> y;
		a[i].a = x;a[i].c = y;
		sum += a[i].a;
	}
	
	if(sum%2) p = 1;
	len = sum / 2;
	
	l = 1,r = n;
	
	while(sum1+p < sum){
		if(a[l].c != a[r].c){
			if(a[l].a > a[r].a){
				x = a[r].a;
				a[r].a -= x;
				a[l].a -= x;
				ans += x;
				sum1 += x*2;
				}
			
			else{
				x = a[l].a;
				a[l].a -= x;
				a[r].a -= x;
				ans += x;
				sum1 += x*2;
				}
			}
		else{
			if(a[l].a > a[r].a){
				x =  a[r].a;
				a[r].a -= x;
				a[l].a -= x;
				sum1+= x*2;
				}
			
			else{
				x =  a[l].a;
				a[l].a -= x;
				a[r].a -= x;
				sum1+= x*2;
				}
			}
		if(a[l].a == 0) l ++;
		if(a[r].a == 0) r --;
		
		}
	cout << ans;
	return 0;
}
