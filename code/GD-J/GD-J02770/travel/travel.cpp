#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f[10]={0,0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f[1]=1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				f[2]=1;
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					f[3]=1;
				}else{
					f[3]=0;
				}
			}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				f[2]=1;
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					f[3]=1;
				}else{
					f[3]=0;
				}
			}else{
				f[2]=0;
			}
		}else{
			f[1]=0;
		}	
	}else{
		f[0]=0;
	}
	for(int i=0;i<4;i++){
		cout<<f[i];
	}
	return 0;
} 
