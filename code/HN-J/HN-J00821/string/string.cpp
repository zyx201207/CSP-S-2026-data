#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,d,r;
int len,cnt;
char c;
bool f;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t >> c;
		if(t>=1e7){
			r=t;
			t=1;
			f=true;
		}
		while(t--){
			s[d]=c;
			d++;
		}
	}
	for(int i=0;i<d;i++){
		if(s[i]!=s[d-i-1]){
			s[d-i-1]=s[i];
			cnt++;
		}
	} 
	if(f==true){
		cnt*=r;
	}
	cout << cnt;
	return 0;
}

