#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1,ans={"0000"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	bool ok=1;
	if(a==b){
		ans[0]='1';
	}else{
		
		ok=0;
	}bool ok1=1;
	if(ok&&a1[0]==b1[0]&&a1[1]==b1[1]){
		ans[1]='1';
	}else{
		ok1=0;
	}if(a1[2]>b1[2])swap(a1[2],b1[2]);
	if(ok&&ok1&&((a1[2]<='C'&&b1[2]<='C')||(a1[2]=='D'&&b1[2]=='F'))){
		ans[2]='1';
	}else{
	}if(ok&&ok1&&((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='D'&&b1[2]=='F'))){
		ans[3]='1';
	}else{
		
	}
	cout<<ans;
	return 0;
}
