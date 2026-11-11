#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;int r1=int(c1[2]),r2=int(c2[2]);
	if(s1==s2) cout<<1;
	else cout<<0;
	
	if(s1==s2&&c1[0]==c2[0]&&c1[1]==c2[1]) cout<<1;
	else cout<<0;
	
	if(s1==s2&&c1[0]==c2[0]&&c1[1]==c2[1]){
		if((min(r1,r2)-67)*(max(r1,r2)-67)>0) cout<<1;
		else if((min(r1,r2)-67)*(max(r1,r2)-67)==0&&((min(r1,r2)-67)==0&&(max(r1,r2)-67)<0)) cout<<1;
		else cout<<0;
	}else cout<<0;
	
	if(s1==s2&&c1[0]==c2[0]&&c1[1]==c2[1]){
		if(((min(r1,r2)-67)*(max(r1,r2)-67)>0)||((min(r1,r2)-67)*(max(r1,r2)-67)==0&&((min(r1,r2)-67)==0&&(max(r1,r2)-67)<0))){
			if((min(r1,r2)-67)-(max(r1,r2)-67)==-1) cout<<1;
			else cout<<0;
		}else cout<<0;
	}else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
