#include<bits/stdc++.h>
using namespace std;
char s[2];
int x[2],l[2],g[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x[0]>>l[0]>>s[0]>>x[1]>>l[1]>>s[1];
	if(s[0]>='D')g[0]=1;
	else g[0]=0;
	if(s[1]>='D')g[1]=1;
	else g[1]=0;
	if(x[0]==x[1]){
		cout<<'1';
		if(l[0]==l[1]){
			cout<<'1';
			if(g[0]==g[1]){
				cout<<'1';
				if(abs(s[0]-s[1])==1)cout<<'1';
				else{
					cout<<"0";
				}
			}else{
				cout<<"00"; 
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
