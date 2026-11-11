#include<bits/stdc++.h>
using namespace std;
string xiang1,hao1,xiang2,hao2,ans;
int flag1,flag2,flag3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>xiang1>>hao1>>xiang2>>hao2; 
	
	if(xiang1==xiang2){
	    ans+='1';	
	    flag1=1;
	}else{
		ans+='0';
		flag1=0;
	}
	
	if(flag1&&hao1[0]==hao2[0]&&hao1[1]==hao2[1]){
	    ans+='1';	
	    flag2=1;
	}else{
		ans+='0';
		flag2=0;
	}
	
	if(flag2&&(hao1[2]>='A'&&hao1[2]<='C'&&hao2[2]>='A'&&hao2[2]<='C')||(hao1[2]>='D'&&hao1[2]<='F'&&hao2[2]>='D'&&hao2[2]<='F')){
	    ans+='1';	
	    flag3=1;
	}else{
		ans+='0';
		flag3=0;
	}
	
	if(flag3&&abs(int(hao1[2]-hao2[2]))==1){
	    ans+='1';	
	}else{
		ans+='0';
	}
	
	cout<<ans<<endl;
	return 0;
}
