#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	int f=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f=0;
		}
	}
	if(f==1){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	int m=a-'A',n=b-'A';
	if(a!=b&&m<=2&&n<=2||m>=3&&n>=3&&a!=b){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(m-n)==1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
