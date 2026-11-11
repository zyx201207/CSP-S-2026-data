//GZ-J00623 遵义市第一中学 况建德 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c_1,c_2,G=0,r,t,y,u;
	char a[1005],p[1005],s_1[3],s_2[3],n,v;
	n='C';
	v='D';
	cin>>c_1;
	for(int i=0;i<3;i++){
		cin>>s_1[i];
		if(i==0){
			r=s_1[i];
		}
		if(i==1){
			t=s_1[i];
		}
	}
	cin>>c_2;
	for(int i=0;i<3;i++){
		cin>>s_2[i];
		if(i==0){
			y=s_2[i];
		}
		if(i==1){
			u=s_2[i];
		}
	}
	if(c_1==c_2){
		cout<<1;
	}else{
		cout<<0000;
		G++;
	}
	if(r==y && t==u && G==0){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		G++;
	}
	if(s_1[2]==v && s_2[2]==n && G==0){
		cout<<0<<0;
		G++;
	}else if(s_1[2]==n && s_2[2]==v && G==0){
		cout<<0<<0;
		G++;
	}else if(G==0){
		if(s_1[2]<n && s_2[2]<v){
			cout<<1;
		}else if(s_1[2]>n && s_2[2]>v){
			cout<<1;
		}else{
			cout<<0<<0;
			G++;
		}
	}
	if(max(s_1[2],s_2[2])-min(s_1[2],s_2[2])==1 && G==0){
			cout<<1;
	}else if(G==0){
		cout<<0;
	}
}
