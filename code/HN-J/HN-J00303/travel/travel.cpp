#include<bits/stdc++.h>
using namespace std;
//int N=1e6+10;
string c1,s1,c2,s2;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int ans1=0;
	for(int i=0;i<s1.size();i++){
		ans1+=s1.size();
	}
	if(s1==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	cout<<ans1;
	return 0;
} 
