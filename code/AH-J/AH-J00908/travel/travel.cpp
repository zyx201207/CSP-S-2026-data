#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1 == b1){
		cout<<1;
		string s1="",s2="";
		char ch1=a2[2],ch2=b2[2];
		s1 += a2[0];
		s1 += a2[1];
		s2 += b2[0];
		s2 += b2[1];
		if(s1 == s2){
			cout<<1;
			if((ch1 == 'A' && ch2 == 'B')||(ch1 == 'A' && ch2 == 'C')||(ch1 == 'B' && ch2 == 'A')||(ch1 == 'B'&& ch2 == 'C')||(ch1 == 'C'&& ch2 == 'A')||(ch1 == 'C'&& ch2 == 'B')||(ch1 == 'D'&& ch2 == 'E')||(ch1 == 'E'&& ch2 == 'D')){
				cout<<1;
				if(abs(ll(ch1 - ch2)) == 1)cout<<1;
				else{
					 cout<<0;
					 return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
