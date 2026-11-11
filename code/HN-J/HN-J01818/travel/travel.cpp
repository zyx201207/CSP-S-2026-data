#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int a[5],b[5];
char c,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	for(int i=0;i<=1;i++){
		a[i]=s[i];
		b[i]=s2[i];
		if(a[i]!=b[i]){
			cout<<"0000";
			return 0;
		}
		if(i==1){
			cout<<1;
		}
	}
	for(int i=0;i<=1;i++){
		a[i]=s1[i];
		b[i]=s3[i];
		c=s1[2];
		c1=s3[2];
		if(a[i]!=b[i]){
			cout<<"000";
			return 0;
		}
		if(i==1){
			cout<<1;
		}
	}
	if(c<=67&&c1<=67||c>67&&c1>67){
		cout<<1;
        if(abs(c-c1)==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<"00";
	}
	return 0;
}
