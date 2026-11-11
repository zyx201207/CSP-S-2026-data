#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<'1';
		ll sum1=(s1[0]-'0')*10+s1[1]-'0';
		ll sum2=(s2[0]-'0')*10+s2[1]-'0';
		if(sum1!=sum2){
			cout<<"000";
		}else{
			cout<<'1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D')){
				cout<<'1';
				if(abs(s1[2]-s2[2])==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
