#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,a;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int cnt = 0 ;
	for(int i = 0;i<n;i++){
		cin>>a>>c;
		int tp = a;
		cnt+=a;
		while(tp--){
			s += c;
		}
	}
	cout<<s<<endl; 
	int res = 0;
	for(int i = 0,j = cnt - 1;;i++,j--){
		if(j <= i){
			break;
		}
		if(s[i] != s[j]){
			res++;
		}
	}
	cout<<res;
	return 0;
}
