#include <bits/stdc++.h>
using namespace std;
string s,c,a;
int main(){
	int n,m,ans=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m;
		cin >> c;
		for(int i=1;i<=m;i++){
		s=s+c;	
		}
	}
	for(int i=s.size();i>=0;i--){
		a=a+s.substr(i,1);
	}
	for(int i=1;i<=s.size();i++){
	if(s.substr(i,1)!=a.substr(i,1)){
		s.substr(i,1);
		ans++;
	}	
    }
    cout << ans-1 << '\n';
    return 0;
}
