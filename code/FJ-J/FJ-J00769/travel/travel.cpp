#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[5];
int fun(string s){
	int num=0;
	for(int i=0;i<=1;i++){
		num=num*10+(s[i]-'0');
	}
	return num;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s3>>s2>>s4;
	int k1=fun(s3),k2=fun(s4);
	if(s1==s2){
		a[1]=1;
		if(k1==k2){
			a[2]=1;
			if(s3[2]>='A'&&s3[2]<='C'&&s4[2]>='A'&&s4[2]<='C'){
				a[3]=1;
				if(abs(s3[2]-s4[2])==1){
					a[4]=1;
				}
			}
			else if(s3[2]>='D'&&s3[2]<='F'&&s4[2]>='D'&&s4[2]<='F'){
				a[3]=1,a[4]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
