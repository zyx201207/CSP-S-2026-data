#include<bits/stdc++.h>
#define int long long
using namespace std;
string ss,cc;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<' '<<s1<<endl;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=1;i++){
			ss+=s1[i],cc+=s2[i];
		}
		//cout<<ss<<' '<<cc<<endl;
		if(ss==cc){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				char c=s1[2],s=s2[2];
				if(abs(c-s)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
//02 01A 02 01B