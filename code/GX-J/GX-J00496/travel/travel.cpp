#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w","stdin");
	freopen("travel.out","r","stdout");
	int n,c1,c2,s1,s2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2>>s1>>s2;
	}
	if(c1!=c2 || s1!=s2){
		cout<<"1111";
	}else{
		cout<<"0000";
		 }		
}
