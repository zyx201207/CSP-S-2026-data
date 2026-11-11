#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans;
char c;
string l;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			l+=c;
		}
	}
	for(int i=0;i<l.size()/2;i++){
		if(l[i]!=l[l.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
