#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll ans,Len,len2;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i]>>c[i];
		Len += a[i];
	}
	Len /= 2;
	ll len = a[n],l = 1,r = n;
	while(l < r){
		if(a[l] > len){
			if(len2+len > Len){
				if(c[l] != c[r])ans += len;
				if(c[l] != c[r])ans -= (len2+len-Len);
				break;
			}
			len2 += len;
			if(c[l] != c[r]) ans += len;
			a[l] -= len;
			r --;
			len = a[r];
		} else if(a[l] == len){
			if(len2+len > Len){
				if(c[l] != c[r])ans += len;
				if(c[l] != c[r])ans -= (len2+len-Len);
				break;
			}
			len2 += len;
			if(c[l] != c[r]) ans += len;
			a[l] -= len;
			l ++;
			r --;
			len = a[r];
		} else {
			if(len2+a[l] > Len){
				if(c[l] != c[r])ans += a[l];
				if(c[l] != c[r])ans -= (len2+a[l]-Len);
				break;
			}
			len2 += a[l];
			if(c[l] != c[r]) ans += a[l];
			len -= a[l];
			l ++;
		}
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/