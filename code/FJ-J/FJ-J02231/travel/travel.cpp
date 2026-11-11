#include<bits/stdc++.h>
using namespace std;
string a,s,d,f,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>d>>f;
	bool u=true;
	for(int z=0;z<=1;z+=1){
		if(a[z]!=d[z]){
			u=false;
		}
	}
	if(u){
		k='1';
		u=true;
		for(int z=0;z<=1;z+=1){
			if(s[z]!=f[z]){
				u=false;
			}
		}
		if(u){
			k=k+'1';
			if((s[2]>='D'&&f[2]>='D')||(s[2]<='C'&&f[2]<='C')){
				k=k+'1';
				char a=s[2],b=f[2];
				if(a-1==b||a+1==b){
					k=k+'1';
				}
				else{
					//cout<<a+1<<' ';
					//cout<<4;
					k=k+'0';
				}
			}
			else{
				//cout<<3;
				k=k+"00";
			}
		}
		else{
			//cout<<2;
			k=k+"000";
		}
	}
	else{
		//cout<<1;
		k="0000";
	}
	cout<<k;
	return 0;
} 
