#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num,cnt;
string s,tmp,c;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==0){
		cout<<0;
		return 0;
	}
	while(n--){
		cin>>num>>c;
		while(num){
			if(num&1)s+=c;
			c=c+c;
			num>>=1;
		}
	}
	tmp=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=tmp[i])cnt++;
	}
	cout<<cnt/2;
	return 0;
}
