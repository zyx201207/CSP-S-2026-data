#include<bits/stdc++.h>
#include<string>
using namespace std;
//#define JUDGE
#define int long long
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * f;
}
const int N = 1e6 + 10;
int n;
int a[N];
int b[N];
int nxt;
int amxa,sum;
char c[N],bc[N];
void input(){
	n = read();
	for(int i = 1;i<=n;i++){
		a[i] = read();
		cin >> c[i];
		amxa = max(amxa,a[i]);
		sum += a[i];
	}
}
int spend(string f){
	int ans = 0;
	int l = 0,r = f.length() - 1;
	while(l <= r){
		if(f[l] != f[r])ans++;
		l++,r--;
	}
	return ans;
}
void solve(){
	input();
	if(n <= 2000 && amxa <= 50){
		string f = "";
		for(int i = 1;i<=n;i++)f += string(a[i], c[i]);		
		cout << spend(f) << endl;
		return;
	}
	if(n <= 200000 && amxa == 1){
		string f(n,c[1]);
		cout << spend(f) << endl;
		return;
	}
	if(n * amxa <= 999999){
		string f = "";
		for(int i = 1;i<=n;i++)f += string(a[i], c[i]);		
		cout << spend(f) << endl;
		return;
	}
	b[1] = a[1],bc[1] = c[1],nxt = 1;
	for(int i = 2;i<= n;i++){
		if(c[i] == c[i - 1])b[nxt] += a[i];
		else b[++nxt] = a[i], bc[nxt] = c[i];
	}
	long long l = 1,r = nxt,ans = 0;
	int al = b[l],ar = b[r];
	while(l <= r){
		if(al < ar){
			ar -= al;
			if(bc[l] != bc[r])ans += al;
			l++;
			al = b[l];				
			if(ar == 0)r--,ar = b[r];
		} else if(al > ar){
			al -= ar;
			if(bc[l] != bc[r])ans += ar;
			r--;
			ar = b[r];				
			if(al == 0)l++,al = b[l];
		} else { 
			if(bc[l] != bc[r])ans += al;
			l ++,r--,al = b[l],ar = b[r];
		}
	}
	cout << ans << endl;
}
signed main( ){
#ifndef JUDGE
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
#endif
	int _ = 1;
	//cin >> _;
	while(_--)solve();
	return 0;
}
