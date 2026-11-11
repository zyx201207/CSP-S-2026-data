#include<bits/stdc++.h>
using namespace std;
string a[2],b[2];
int ans[4];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	
	if(a[0][0]==b[0][0]&&a[0][1]==b[0][1]){
		ans[0]=1;
		if(a[1][0]==b[1][0]&&a[1][1]==b[1][1]){
			ans[1]=1;
			if(a[1][2]<='C'&&b[1][2]<='C'){
				ans[2]=1;
				if(a[1][2]=='B'||b[1][2]=='B') ans[3]=1;
			}
			if(a[1][2]>'C'&&b[1][2]>'C'){
				ans[2]=ans[3]=1;
			}
		}
	}
	
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<endl;
	
	return 0;
}

