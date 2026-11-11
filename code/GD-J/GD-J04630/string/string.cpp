#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
long long zs = 0,zd,ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
		zs += a[i];
		for(int j = 0;j < a[i];j++){
			s += c[i];
		}
	}
	bool ll = false;
	if(zs % 2 == 0) ll = true;
	if(ll){
		for(int l = zs/2-1,r = zs/2;l >= 0,r < zs;l--,r++){
			if(s[l] != s[r]) ans++;
		}
	}else{
		for(int l = zs/2-1,r = zs/2+1;l >= 0,r < zs;l--,r++){
			if(s[l] != s[r]) ans++; 
		}
	}
	cout << ans;
	return 0;
} 
