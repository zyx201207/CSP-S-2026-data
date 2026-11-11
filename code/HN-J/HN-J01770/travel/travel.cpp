#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	bool a=true;
	if(c1==c2){
		cout<<"1";
	}
	
	else{
		cout<<"0";
		a=false;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			a=false;
		}
	}
	if(a){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	int b=s1[2]+0-'0',c=s2[2]+0-'0';
	if(((b<=19 && c<=19) || (b>19 && c>19))&& a){
		cout<<"1";
	}
	else{
		cout<<0;
		a=false;
	}
	if(b>c && (b-c==1 && a)){cout<<1;}
	else if(b<c && (c-b==1 && a)){cout<<1;}
	else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
