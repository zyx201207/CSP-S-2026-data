#include<bits/stdc++.h>
#define ll long long
using namespace std;
string r,r1,x,x1;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	//打开文件 
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	bool c=false,d=false;
	cin>>r>>r1>>x>>x1;
	if(x==r){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(r1[0]==x1[0]&&r1[0]==x1[0]&&r1[1]==x1[1]&&r1[1]==x1[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	char R=r1[2];
	char X=x1[2];
	if(R>='A'&&R<='C' && X>='A'&&X<='C'){
		cout<<1;
		c=true;
	}else if(R>='D'&&R<='E'&&X>='D'&&X<='E'){
		cout<<1;
		d=true;
	}else{
		cout<<0<<0;
		return 0;
	} 
	
	if(c==true){
		if(R=='A'&&X=='C' || R=='C'&&X=='A'){
			cout<<0;
		}else{
			cout<<1;	
		}  
	}else if(d==true){
		cout<<1; 
	}
	
		
	//关闭文件 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
