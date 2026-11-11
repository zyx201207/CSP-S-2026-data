#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll c1,c2;
	char s11,s12,s13,s21,s22,s23;
	cin>>c1;
	cin>>s11>>s12>>s13;
	cin>>c2;
	cin>>s21>>s22>>s23;
	if(c1==c2){
		cout<<"1";
	}if(c1!=c2){
		cout<<"0000";
		return 0;
	}if((s11-'0')*10+(s12-'0')==(s21-'0')*10+(s22-'0')){
		cout<<"1";
	}if((s11-'0')*10+(s12-'0')!=(s21-'0')*10+(s22-'0')){
		cout<<"000";
		return 0;
	}if((s11-'0')*10+(s12-'0')==(s21-'0')*10+(s22-'0')){
		if((s13>='A' and s13<='C' and s23>='A' and s23<='C') or (s13>='D' and s13<='F' and s23>='D' and s23<='F')){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}if((s11-'0')*10+(s12-'0')==(s21-'0')*10+(s22-'0')){
		if((s13>='A' and s13<='C' and s23>='A' and s23<='C') or (s13>='D' and s13<='F' and s23>='D' and s23<='F')){
			if(s13>s23 and s13-1==s23){
				cout<<"1";
				return 0;
			}if(s13>s23 and s13-1!=s23){
				cout<<"0";
				return 0;
			}if(s13<s23 and s13+1==s23){
				cout<<"1";
				return 0;
			}if(s13<s23 and s13+1!=s23){
				cout<<"0";
				return 0;
			}
		}
	}

	return 0;
}

