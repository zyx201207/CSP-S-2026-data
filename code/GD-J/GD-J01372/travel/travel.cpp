#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<0<<0<<0<<0;
	else{
		cout<<1;
		if(s1[1]==s2[1]){
			cout<<1;
			if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
				cout<<1;
				if(char(int(s1[2])+1)==s2[2]||char(int(s1[2])-1)==s2[2]) cout<<1;
				else cout<<0;
			}
			else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
				cout<<1;
				if(char(int(s1[2])+1)==s2[2]||char(int(s1[2])-1)==s2[2]) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
