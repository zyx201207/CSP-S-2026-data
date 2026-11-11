#include<bits/stdc++.h>
using namespace std;
int a,b,ans[10];
string s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>a>>s>>b>>c;
	if(a==b){
		ans[1]=1;
		if(s[0]==c[0]&&s[1]==c[1]){
			ans[2]=1;
			if(s[2]<='C'&&c[2]<='C'){
				ans[3]=1;
				if((abs((int)(s[2]-c[2])))==1){
					ans[4]=1;
				}
			}
			else if(s[2]>'C'&&c[2]>'C'){
				ans[3]==1;
				if((abs((int)(s[2]-c[2])))==1){
					ans[4]=1;
				}
			}
//			if(ans[3]==1){
//				cout<<(abs((int)(s[2]-c[2])))<<" ";
//				if((abs((int)(s[2]-c[2])))==1){
//					ans[4]==1;
//				}
//			}
		}
		else ans[2]=0;
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
} 
