#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
string a1,a2,b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int s1,s2;
	s1=(a2[0]-'0')*10+a2[1];
	s2=(b2[0]-'0')*10+b2[1];
	if(s1==s2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int z1=a2[2]-'A',z2=b2[2]-'A';
	if((z1>=3&&z2>=3)||(z1<3&&z2<3)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(z1-z2)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
