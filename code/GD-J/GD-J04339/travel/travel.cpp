#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+7;
string sa,sb,sc,sd;
int ans;

int chk(){
	if(sb[2]=='A'&&sd[2]=='B') return 2;
	if(sb[2]=='A'&&sd[2]=='C') return 1;
	if(sb[2]=='B'&&(sd[2]=='A'||sd[2]=='C')) return 2;
	if(sb[2]=='C'&&sd[2]=='A') return 1;
	if(sb[2]=='C'&&sd[2]=='B') return 2;
	if(sb[2]=='D'&&sd[2]=='F')  return 2;
	if(sb[2]=='F'&&sd[2]=='D') return 2;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cin>>sa>>sb>>sc>>sd;
	if(sa==sc){
		ans++;
		if(sb[0]==sd[0]&&sb[1]==sd[1]){
			ans++;
			ans+=chk();
		}
	}
	for(int i=1;i<=ans;i++) cout<<"1";
	for(int i=1;i<=4-ans;i++) cout<<"0";
	return 0;
}
