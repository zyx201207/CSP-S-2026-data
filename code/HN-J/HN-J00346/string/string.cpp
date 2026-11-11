#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
char c[100005],b;
long long s,cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cin >> b;
		for(int j = 1;j <= a[i];j++){
			cnt++;
			c[cnt] = b;
			if(c[cnt] >= 'a' && c[cnt] <= 'z') s++;
		}
	}
	for(int i = 1;i <= s / 2;i++){
		if(c[i] != c[s + 1 - i])  ans++;
	}
	//cout << c[18];
	//for(int i = 1;i <= s;i++)  cout << c[i] << " ";
	cout << ans;
	
	
	
	
	return 0;
}
