#include<bits\stdc++.h>
using namespace std;
int p,a,b,c,ans;
string n,m,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(n==m){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char ss1=min(s1[2],s2[2]),ss2=max(s2[2],s1[2]);
			if(ss1>='D'||ss2<='C'){
				cout<<1;
				if(ss1!='C'&&ss2-ss1==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	} else cout<<"0000";
}
