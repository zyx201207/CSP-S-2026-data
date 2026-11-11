#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int m1=(s1[0]-'0'*10)+s1[1]-'0';
		int m2=(s2[0]-'0'*10)+s2[1]-'0';
		char a1=s1[2],a2=s2[2];
		if(m1==m2){
			cout<<1;
			if(a1=='B'||a1=='A'||a1=='C'){
				if(a2=='B'||a2=='A'||a2=='C'){
					cout<<1;
					if(a1=='B'||a2=='B') cout<<1;
					else cout<<a1<<a2<<"0";
				}else{
					cout<<"00";
				}
			}else{
				if(a2=='D'||a2=='F'){
					cout<<11;
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
