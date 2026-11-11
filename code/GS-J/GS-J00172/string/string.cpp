#include <iostream>
using namespace std;

int n, s[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s[i] >> c[i];
	}
	
	int l=0, r=n-1;
	while(l<r){
		int v=min(s[l], s[r]);
		if(c[l]!=c[r]){
			ans+=v;
		}
		s[l]-=v;
		if(!s[l])l++;
		s[r]-=v;
		if(!s[r])r--;
	}
	
	cout << ans;
	
	return 0;
}
