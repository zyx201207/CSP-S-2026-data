#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<2;i++){
		if(c1==c2){
			c1=c2="1";
		}else{
			c1=c2="0";
		}
		if(s1!=s2){
			s1=s2="1";
		}else{
			s1=s2="0";
		}
	}
	cout<<c1<<s1<<c2<<s2;
	return 0;
} 

