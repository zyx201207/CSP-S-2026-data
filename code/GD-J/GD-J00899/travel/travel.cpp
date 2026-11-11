#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout<<0<<endl;
				}else cout<<1<<endl;
			}else if(s1[2]>'C'&&s2[2]>'C'){
				cout<<11<<endl;
			}else{
				cout<<"00"<<endl;
			}
		}else cout<<"000"<<endl;
	}else cout<<"0000"<<endl;
	return 0;
}
