//GZ-J00352 遵义市第四中学  罗永淇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a[1]==b[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[1]==b1[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(a1[2]<='C'&&a1[2]>='A'){
		if(b1[2]<='C'&&b1[2]>='A'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(b1[2]>='D'&&b1[2]<='F'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(a1[2]+1==b1[2]||a1[2]-1==b1[2]){
		cout<<1;
	}else if((a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&b1[2]=='D')) cout<<1;
	else cout<<'0';
	return 0;
}
