//GZ-j00638 遵义市第四初级中学  陈崇桓 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,z1[2];
	char c2,z2[2];
	cin>>c1;
	for(int i=0;i<=2;++i){
		cin>>z1[i];
	}
	cin>>c2;
	for(int i=0;i<=2;++i){
			cin>>z2[i];
	}
	if(c1=c2&&c1!=1&&c1!=16){
	cout<<1;
	}else{
			cout<<0;
	}
	if(z1[0]==z2[0]&&z1[1]==z1[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if('A'<z1[2]&&z1[2]<'C'&&'A'<z2[2]&&z2[2]<'C'||'D'<z1[2]&&z1[2]<'F'&&'D'<z2[2]&&z2[2]<'F'){
	cout<<1;
}else{
	cout<<0;
}	if(z1[2]+1==z2[2]&&z1[2]+1!='D'){
	cout<<1;	
	}else{
	cout<<0;
	}
	return 0;
}

