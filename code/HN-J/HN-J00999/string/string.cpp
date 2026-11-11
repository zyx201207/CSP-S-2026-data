#include<bits/stdc++.h>
using namespace std;
int n,sl,zc;
char s[9999999];
char zm;
hw(char sz[9999999],int zc){
	
	char fz[zc+1];
	for(int i=zc;i>=0;i--){
		fz[zc-i]=sz[i];
	}
	for(int i=0;i<=zc;i++){
		if(fz[i]!=sz[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	cin>>n;
	
	while(n--){ 
		cin>>sl>>zm;
		for(int j=0;j<=sl;j++){
			s[zc]=zm;
			zc++;
		}
	}
	for(int j=0;j<zc;j++){
		if(hw(s,zc)==1){
			cout<<j-1;
			return 0;
		}else{
			s[zc-j]=s[j];
		}
	}
	return 0;
} 
