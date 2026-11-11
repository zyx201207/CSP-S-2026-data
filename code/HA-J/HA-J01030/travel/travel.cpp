#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool cheak(char a1,char a2){
	if(a1>a2)swap(a1,a2);
	if(a2<='C')return 1;
	if(a1>='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(cheak(s1[2],s2[2])){
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
} // 100% AC
