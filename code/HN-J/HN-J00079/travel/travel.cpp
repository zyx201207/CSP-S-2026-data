#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d,num;
	cin>>a>>b>>c>>d;
	if(a==c){
		num+="1";
	}else{
		num+="0";
	}
	
	if(b[1]==d[1]){
		if(b[0]==d[0]){
			num+="1";
		}
	}else{
		num+="0";
	}
	
	if((b[2]=='A' or b[2]=='B' or b[2]=='C') and (d[2]=='A' or d[2]=='B' or d[2]=='C')){
		num+="1";
	}else if((b[2]=='D' or b[2]=='E') and (d[2]=='D' or d[2]=='E')){
		num+="1";
	}else{
		num+="0"; 
	}
	
	if(b[2]+1==d[2] or b[2]-1==d[2]){
		num+="1";
	}else{
		num+="0";
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
