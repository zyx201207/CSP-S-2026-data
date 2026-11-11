#include<bits/stdc++.h>
using namespace std;


string s;
string s1;
string s2;
char zf;
char zf1;
char a;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ws=0;
	int n;
	cin>>n;
	bool cf=false;
	long long zws=0;
	for(long long int i=1;i<=n;i++){
		cin>>ws>>zf;
		if(zf1==zf){
			cf=true;
		}else{
			cf=false;
		}
		
		zws+=ws;
		zf1=zf;
		if(i==1){
			a=zf;
		}
		for(long long int j=0;j<ws;j++){
			s+=zf;
		}
	}
	if(cf){
		cout<<0;
		return 0;
	}
	long long int gs=0;
	
	for(long long int i=zws-1;i>=0;i--){
		bool flag=true;
		s1="";
		s2="";
		s[i]=a;
		gs++;
		for(long long int j=0;j<zws;j++){
			s1+=s[j];
		}
		for(long long int k=zws-1;k>=0;k--){
			s2+=s[k];
		}
		for(int l=0;l<zws;l++){
			if(s1[l]!=s2[l]){
				flag=false;
				break;
			}
		}
		if(flag){
			break;
	    }
	}
	cout<<gs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
