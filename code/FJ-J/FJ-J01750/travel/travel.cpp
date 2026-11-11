#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[4],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++) cin>>s1[i];
	cin>>c2;
	for(int i=1;i<=3;i++) cin>>s2[i];
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
			if(((s1[3]=='A')||(s1[3]=='B')||(s1[3]=='C'))&&
			((s2[3]=='A')||(s2[3]=='B')||(s2[3]=='C'))||
			((s1[3]=='D')||(s1[3]=='F'))&&
			((s2[3]=='D')||(s2[3]=='F'))){
				cout<<"1";
				if((char)(s1[3]+1)==s2[3]||(char)(s1[3]-1)==s2[3]){
					cout<<"1"<<"\n";
				}else cout<<"0"<<"\n";
			}else cout<<"00"<<"\n";
		}else cout<<"000"<<"\n";
	}else cout<<"0000"<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*created by luve on 2026/10/31 8:45 100pts(?*/
