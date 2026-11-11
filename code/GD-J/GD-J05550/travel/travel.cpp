#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	char x[10]={'0','A','B','C','D','E','0'};
	cin>>c1>>s1>>c2>>s2;
	
	int ca=2,cb=2;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')ca=1;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')cb=1;
	
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if(ca==cb){
				cout<<1;
				int b;
				for(int i=1;i<=5;i++){
					if(s1[2]==x[i]){
						b=i;
						break;
					}
				}
				
				if(s2[2]==x[b+1] || s2[2]==x[b-1]){
					cout<<1;
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
	
}


