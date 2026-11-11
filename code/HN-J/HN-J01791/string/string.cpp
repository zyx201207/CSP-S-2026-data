#include<bits/stdc++.h>
using namespace std;
long long n, a, ans, cnt;
string s, k;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> a;
		cin >> c;
		for(int i = 1; i <= a; i++){
			s+=c;
		}
	}
	k = s;
	reverse(k.begin(),k.end());
	if(k==s){
		cout << 0;
		return 0;
	}
	if(k.size()%2!=0){
		for(int i = k.size()/2,j=k.size()/2; i>=0, j<=k.size()-1; i--,j++){
			if(k[i]!=k[j]) ans++;
		}
	} else {
		for(int i = k.size()/2-1,j=k.size()/2; i>=0, j<=k.size()-1; i--,j++){
			if(k[i]!=k[j]) ans++;
		}
	}
	cout << ans;
	return 0;
}

