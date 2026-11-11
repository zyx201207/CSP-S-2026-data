//GZ-J00241 个人报名 吴狄阳 
#include<bits/stdc++.h>
using namespace std;
int o[5];
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int p=0;
	for(int i=0;i<4;i++){
		cin>>o[i];
		o[i]=1;
	}
	for(int i=0;i<4;i++){
		int x,y,z,a;
		cin>>x>>y>>z>>a;
		if(x!=z){
			o[0]=0;
		}
		if(i>2){
			p=1;
		}
		if(y!=a&&p==0){
			o[1]=0;
		}
		if(p==1&&y>='D'&&a>='D'||p==1&&y<='C'&&a<='C'){
			o[2]=1;
		}
		else{
			o[2]=0;
		}
		if(p==1&&y!='C'&&a!='D'&&y!='D'&&a!='C'&&a-y!=1&&y-a!=1){
			o[3]=0;
		}
	}
	for(int i=0;i<4;i++){
		cout<<o[i];
	}
}
