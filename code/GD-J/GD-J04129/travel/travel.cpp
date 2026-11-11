#include<bits/stdc++.h>
using namespace std;
int A,B;
char ans[4];
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>a>>B>>b;
	if(A==B){
		ans[0]='1';
		int as=(a[0]-'0')*10+(a[1]-'0');
		int bs=(b[0]-'0')*10+(b[1]-'0');
		if(as==bs){
			ans[1]='1';
			if(a[2]=='D'&&b[2]=='F'||b[2]=='D'&&a[2]=='F'){
				ans[2]='1';
				ans[3]='1';
			}else if(a[2]!='D'&&b[2]!='F'&&a[2]!='F'&&b[2]!='D'){
				ans[2]='1';
				if(abs(a[2]-b[2])==1){
					ans[3]='1';
				}else ans[3]='0';
			}else{
				ans[2]='0';
				ans[3]='0';
			}
		}else{
			ans[1]='0';
			ans[2]='0';
			ans[3]='0';
		}
		
	}else {
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
} 
