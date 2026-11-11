#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
string c,s,cc,ss;
map<char,int> mp,mpp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;mpp['A']=1;mpp['B']=2;mpp['C']=3;mpp['D']=5;mpp['E']=6;
	mp['D']=mp['E']=2;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<1;
			if(mp[s[2]]==mp[ss[2]]){
				cout<<1;
				if(abs(mpp[s[2]]-mpp[ss[2]])==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0; 
}

