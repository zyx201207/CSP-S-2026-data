#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	int n=18;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2){
			cout<<"1";
		}else cout<<"0";
		if(s1==1&&s2==1){
			cout<<"1";
		}else if(s1==2&&s2==2){
			cout<<1;
		}else cout<<"0";
 		if(s1<=n&&s2<=n){
			cout<<"1";
		}else cout<<"0";
		if(s1+1==s2||s2+1==s1){
			cout<<"1";
		}else cout<<"0";
	return 0;
}
