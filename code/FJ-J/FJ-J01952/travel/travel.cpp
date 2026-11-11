#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1=0,n2=0;
	
	cin>>c1>>c2>>s1>>s2;
	n1=n1+c2%100;
	n2=n2+s2%100;
	if(c1==s1){
		cout<<"0000";
		return 0;
	}
	else if(c1!=s1){
		cout<<"1";
		}
	if(c2/100==s2/100){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(n1<68||n2<68&&n1>67||n2>67){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(n1+1==n2||n1!='C'&&n1-1==n2||n1!='D'){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
