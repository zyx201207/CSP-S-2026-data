#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;

string s1,s2,s3,s4;
int n,m;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s1>>m>>s2;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s1[2]=='D' && s2[2]!='F' || s1[2]=='F' && s2[2]!='D' || s2[2]=='D' && s1[2]!='F' || s2[2]=='F' && s1[2]=='D'){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}

