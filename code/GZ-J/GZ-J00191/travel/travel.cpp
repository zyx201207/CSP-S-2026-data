//GZ-J00191  ¿ÓÓ£ª∏  
#include <bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];

int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1[2]=='F')s1[2] = 'E';
	if(s2[2]=='F')s2[2] = 'E';
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<1;
	else cout<<0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C'&&s2[2]>='D'){
				cout<<0;
			}
			else cout<<1;
			if(((char(s1[2])+1==char(s2[2]))&&s1[2]!='C')||((char(s1[2])-1==char(s2[2]))&&s2[2]=='C')){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
