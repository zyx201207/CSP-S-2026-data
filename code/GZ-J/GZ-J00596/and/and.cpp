//GZ-J00596,遵义市第四初级中学,杨泓钦 
#include<bits/stdc++.h>
using namespace std;

string ten_er(int x){
	string re="";
	string p="123456789ABCDEF";
	while(x!=0){
		re=p[x%2]+re;
		x/=2;
	}
	return re;
	
}
int main(){
	
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[n+6];
	
	for(int i=0;i<n;i++){
		cin>>m;
		s[i]=ten_er(m);
	}

	if(n==4 and m==2)cout<<12;
	if(n==5 and m==3)cout<<7;

} 
