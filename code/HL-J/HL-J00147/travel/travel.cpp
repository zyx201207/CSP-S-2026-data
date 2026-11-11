#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string cc,sc,ss,sz;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc>>sc>>ss>>sz;
	if(cc==ss){
		cout<<1;
	}else cout<<0;
	if(cc==ss and sc[0]==sz[0] and sc[1]==sz[1]){
		cout<<1;
	}else cout<<0;
	if(cc==ss and sc[0]==sz[0] and sc[1]==sz[1]){
		if(sc[2]=='A' and sz[2]=='B'){
			cout<<1;
		}else if(sc[2]=='C' and sz[2]=='B'){
			cout<<1;
		}else if(sc[2]=='B' and sz[2]=='A'){
			cout<<1;
		}else if(sc[2]=='A' and sz[2]=='C'){
			cout<<1;
		}else if(sc[2]=='C' and sz[2]=='A'){
			cout<<1;
		}else if(sc[2]=='D' and sz[2]=='F'){
			cout<<1;
		}else if(sc[2]=='F' and sz[2]=='D'){
			cout<<1;
		}else if(sc[2]=='B' and sz[2]=='C'){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	if(cc==ss and sc[0]==sz[0] and sc[1]==sz[1]){
		if(sc[2]=='A' and sz[2]=='B'){
			cout<<1;
		}else if(sc[2]=='B' and sz[2]=='A'){
			cout<<1;
		}else if(sc[2]=='B' and sz[2]=='C'){
			cout<<1;
		}else if(sc[2]=='C' and sz[2]=='B'){
			cout<<1;
		}else if(sc[2]=='D' and sz[2]=='F'){
			cout<<1;
		}else if(sc[2]=='F' and sz[2]=='D'){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	return 0;
} 
