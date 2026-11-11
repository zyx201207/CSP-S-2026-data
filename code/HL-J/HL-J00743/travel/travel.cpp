#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,n1,s2,n2;
	cin>>s1>>n1>>s1>>n1;
	if(s1==s2&&n1==n1){
		cout<<"1111";
	}
	else if(s1==s2&&n1[1]==n2[1]){
		cout<<"1000";
	}
	else if(s1!=s2&&n1==n2){
		cout<<"0000";
	}
	return 0;
}