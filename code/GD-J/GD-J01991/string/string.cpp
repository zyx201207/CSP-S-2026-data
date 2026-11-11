#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll len=0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len+=a[i];
	}
	string s;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			s+=c[i];
		}
	}
	ll cnt=0;
	for(int i = 0,j=len-1;i<len/2 && j>len/2;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
