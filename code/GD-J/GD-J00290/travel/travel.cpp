#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c2,s2;
	cin>>c>>s>>c2>>s2;
	if(c[0]==c2[0]&&c[1]==c2[1]){
		cout<<1;
	}
	else cout<<0;

	if(c[0]==c2[0]&&c[1]==c2[1]&&s[0]==s2[0]&&s[1]==s2[1]){
		cout<<1;

		}
	else cout<<0;			
	int a=(int(s[2]-'A')+1)*(int(s2[2]-'A')+1);
	if((c[0]==c2[0]&&c[1]==c2[1]&&s[0]==s2[0]&&s[1]==s2[1])&&(a==20||a==6||a==3||a==2)){
			cout<<1;
        }
	else cout<<0;
	if((c[0]==c2[0]&&c[1]==c2[1]&&s[0]==s2[0]&&s[1]==s2[1])&&(a==20||a==6||a==3||a==2)&&abs(int(s[2]-'A')-int(s2[2]-'A'))==1){
		cout<<1;
		}
	else cout<<0;
			
	return 0;
} 
