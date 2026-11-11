#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char a[5],b[5];
	cin>>c1>>s1>>c2>>s2;
	a[1]=s1[0];
	a[2]=s1[1];
	a[3]=s1[2];
	b[1]=s2[0];
	b[2]=s2[1];
	b[3]=s2[2];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int flag=1;
	for(int i=1;i<=2;i++){
		if(!(a[i]==b[i])){
			flag=0;
			cout<<0;
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	if(flag==1){
		cout<<1;
		if(a[3]<='C'&&b[3]<='C'){
			cout<<1;
		}else if(a[3]>='D'&&b[3]>='D'){
			cout<<1;
		}else{
			cout<<0;
			cout<<0;
			return 0;
		}
		if((int(a[3]-b[3])==1)||(int(a[3]-b[3])==-1)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
} 
