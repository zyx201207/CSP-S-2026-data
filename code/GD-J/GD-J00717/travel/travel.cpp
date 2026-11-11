#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int sum1=0,sum2=0;
	for(int i=0;i<2;i++){
		sum1+=s1[i]-'0';
		sum2+=s2[i]-'0';
	}
	if(sum1==sum2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]>='D'&&s2[2]<='C')||(s1[2]<='C'&&s2[2]>='D')){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	string a,b;
	a=s1[2];
	b=s2[2];
	string zimu[5]={"A","B","C","D","F"};
	int aa,bb;
	for(int i=0;i<5;i++){
		if(a==zimu[i]){
			aa=i;
		}else if(b==zimu[i]){
			bb=i;
		}
	}
	if((aa==bb+1)||(bb==aa+1)){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
