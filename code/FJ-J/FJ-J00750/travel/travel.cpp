#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string ts1,ts2;
bool get_side(char x){
	if (x=='D' or x=='F') return 0;
	else return 1;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>ts1>>c2>>ts2;
	int s1=(ts1[0]-'0')*10+(ts1[1]-'0'),s2=(ts2[0]-'0')*10+(ts2[1]-'0');
	if (c1==c2){
		cout<<1;
		if (s1==s2){
			cout<<1;
			if (get_side(ts1[2])==get_side(ts2[2])){
				cout<<1;
				if (ts1[2]-'0'==ts2[2]-'0'+1 or ts1[2]-'0'==ts2[2]-'0'-1) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
