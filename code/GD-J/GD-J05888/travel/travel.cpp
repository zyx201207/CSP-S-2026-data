#include<bits/stdc++.h>
using namespace std;
int c1,c2,a[5],b[5],flag=1;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
		flag=0;
	}
	for(int i=0;i<3;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(a[0]==b[0] && a[1]==b[1] && flag!=0) cout<<"1";
	else{
		cout<<"0";
		flag=0;
	}
	if(a[2]<=67 && b[2]>=68 || a[2]>=68 && b[2]<=67 || flag==0){
		cout<<"0";
		flag=0;
	}
	else cout<<"1";
	if(a[2]==b[2]+1 || b[2]==a[2]+1){
		if(flag==0) cout<<"0";
		else cout<<"1";
	}
	else cout<<"0";
	flag=1;	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
