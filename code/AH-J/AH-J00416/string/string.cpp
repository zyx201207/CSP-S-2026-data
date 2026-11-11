#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,cnt;
char c;
string s,t;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>q>>c;
		for(int i=1;i<=q;i++){
			s+=c;
			//cout<<s<<endl;
			cnt++;
		}
	}
	int cnt2=0;
	for(int i=cnt-1;i>=0;i--){
		t+=s[i];
	}
	for(int i=0;i<cnt;i++){
		//cout<<s[i]<<" "<<t[i]<<endl;
		if(s[i]!=t[i])cnt2++;
	}
	cout<<cnt2/2;
}
