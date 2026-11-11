#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}for(int i=0;i<2;i++){
		a+=s1[i];
		b+=s2[i];
	}if(a==b){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')||s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
