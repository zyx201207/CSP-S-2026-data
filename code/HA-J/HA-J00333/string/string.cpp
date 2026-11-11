#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
st s,a;
ll n,m,ans,cnt=0;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> m >> x;
		for(int j=0;j<m;i++){
			s+=x;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		a[cnt]=s[i];
		cnt++;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=a[i]){
			ans++;
		}
	}
	cout << ans/2;
	return 0;
}
