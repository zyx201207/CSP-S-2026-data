#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		cout<<"0000";
	else{
		cout<<"1";
		string t1=s1.substr(0,2),t2=s2.substr(0,2);
		if(t1!=t2)
			cout<<"000";
		else{
			cout<<"1";
			if((s1[2]>='D'&&s2[2]<='C')||(s1[2]<='C'&&s2[2]>='D'))
				cout<<"00";
			else{
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
