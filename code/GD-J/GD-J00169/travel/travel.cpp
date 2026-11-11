#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int k1=s1[2]-'A'+1,k2=s2[2]-'A'+1;
			if((k1<=3&&k2<=3)||(k1>=4&&k1<=5&&k2>=4&&k2<=5)){
				cout<<1;
				if(k1>k2)swap(k1,k2);
				if(k2-k1==1&&k2!=4&&k1!=3)
					cout<<"1\n";
				else
					cout<<"0\n";
			}else{
				cout<<"00\n";
				return 0;
			}
		}else{
			cout<<"000\n";
			return 0;
		}
	}else{
		cout<<"0000\n";
		return 0;
	}
	return 0;
}
// 8:50左右？：T1 并通过大样例 
