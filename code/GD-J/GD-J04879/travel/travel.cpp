#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			string a=s1.substr(2,1),b=s2.substr(2,1);
			if(a[0]>b[0]){
				string c=a;
				a=b;
				b=c;
			}
			if(a=="A"||a=="B"||a=="C"){
				if(b=="A"||b=="B"||b=="C"){
					cout<<1;
					if(b[0]-a[0]==1)cout<<1;
					else cout<<0;
				}else cout<<"00";
			}
			else if(a=="D"||a=="F"){
				if(b=="D"||b=="F"){
					cout<<1;
					if(b[0]-a[0]==1)cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
