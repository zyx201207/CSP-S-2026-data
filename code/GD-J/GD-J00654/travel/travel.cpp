#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
string ans;
bool iff=false,ifff=false,iffff=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		ans+='1';
		iff=true;
	}else{
		ans+='0';
	}
	if(iff==true&&aa[1]==bb[1]&&aa[0]==bb[0]){
		ans+='1';
		ifff=true;
	}else{
		ans+='0';
	}
	if(ifff==true&&aa[2]>='A'&&aa[2]<='C'&&bb[2]>='A'&&bb[2]<='C'){
		ans+='1';
		iffff=true;
	}else{
		if(ifff==true&&aa[2]>='D'&&aa[2]<='F'&&bb[2]>='D'&&bb[2]<='F'){
			ans+='1';
			iffff=true;
		}else{
			ans+='0';
		}
	}
	if(iffff==true&&(aa[2]+1==bb[2]||aa[2]-1==bb[2])){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0; 
} 
