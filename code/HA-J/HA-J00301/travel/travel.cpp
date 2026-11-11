#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e6;
//172.16.12.5
string aa,bb,cc,dd;
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>aa>>bb>>cc>>dd;
	string ans = "";
	if(aa == cc){
		ans+='1';
		if(bb[0] == dd[0] && bb[1] == dd[1]){
			ans+='1';
			if((bb[2] <= 'C' && dd[2]<='C') || (bb[2] <= 'F' && dd[2]<='F' && bb[2] >= 'D' && dd[2] >='D')){
				ans+='1';
				if(bb[2]+1==dd[2] || dd[2] +1 ==bb[2]){
					cout<<"1111";
					exit(0);
				}
				else{
					cout<<"1110"<<endl;
				}
			}
			else{
				cout<<"1100"<<endl;
				exit(0);
			}
		}
		else{
			cout<<"1000"<<endl;
			exit(0);
		}
	}
	else{
		cout<<"0000"<<endl;
		exit(0);
	}
	
}