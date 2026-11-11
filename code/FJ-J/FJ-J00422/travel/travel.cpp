#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
bool vis[10];
char ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<'1';
		vis[0]=1;
	}else{
		cout<<"0000";
		return 0;
	}if(a1[0]==b1[0]&&a1[1]==b1[1]&&vis[0]==1){
		cout<<'1';
		vis[1]=1;
	}else{
			cout<<'0';
			vis[1]=0;
		}if((((a1[2]>='A'&&a1[2]<='C')&&(b1[2]>='A'&&b1[2]<='C'))||((a1[2]>='D'&&a1[2]<='F')&&(b1[2]>='D'&&b1[2]<='F')))&&vis[1]==1){
		cout<<'1';
		vis[2]=1;
	}else{
			cout<<'0';
		}if(vis[2]==1){
		if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='C'&&b1[2]=='B')||(a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&b1[2]=='D')&&vis[2]==1){
		cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
			cout<<'0';
		}
	return 0;
	
}
