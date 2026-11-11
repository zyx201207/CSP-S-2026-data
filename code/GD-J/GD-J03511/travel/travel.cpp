#include<bits/stdc++.h>
using namespace std;
int cid,rid,pid,cid2,rid2,pid2;
string s1,s2;
void solve(){
	cin>>cid>>s1>>cid2>>s2;
	rid=(s1[0]-'0')*10+(s1[1]-'0'),rid2=(s2[0]-'0')*10+(s2[1]-'0');
	pid=s1[2]-'A',pid2=s2[2]-'A';
	if(pid==3) pid=4;
	if(pid2==3) pid2=4; 
	if(cid!=cid2) cout<<"0000\n";
	else if(rid!=rid2) cout<<"1000\n";
	else if(min(pid,pid2)<=3&&max(pid,pid2)>=4) cout<<"1100";
	else if(abs(pid-pid2)!=1) cout<<"1110\n";
	else cout<<"1111\n"; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
