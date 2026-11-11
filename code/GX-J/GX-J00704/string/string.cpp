#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll x=0,f=1;char ch = getchar();
    while(ch < '0'||ch > '9'){if(ch == '-')f=-1;ch = getchar();}
    while(ch >='0'&&ch <='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 2e5+10;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ll n = read();
	ll cnt = 0;
	string s = " ";
	for(int i = 1;i <= n;i ++){
		a[i] = read();
		cnt += a[i];
		cin >> c[i];
		for(int j = 1;j <= a[i];j ++) s+=c[i];
	}
	ll cnt1 = 0;
	ll mid = cnt/2+1;
	for(int i = 1;i <= mid;i ++){
		if(s[i] != s[cnt+1-i]){
			cnt1 ++;
		}
	}
	printf("%lld",cnt1);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
