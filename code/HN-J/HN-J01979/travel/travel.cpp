#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[4],s2[4];
	int c1,c2;
	bool ans[4]={0};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
		char l1=s1[2],l2=s2[2];
		int x1=(s1[0]-'0')*10+(s1[1]-'0'),x2=(s2[0]-'0')*10+(s2[1]-'0');
		if(x1==x2){
			ans[1]=1;
		}
		if(ans[1]&&l1>='A'&&l1<='C'&&l2>='A'&&l2<='C'){
			ans[2]=1;
		}
		if(ans[1]&&l1>='D'&&l1<='F'&&l1!='E'&&l2>='D'&&l2<='F'&&l2!='E'){
			ans[2]=1;
		}
		if(ans[2]&&(abs(l1-l2)==1)){
			ans[3]=1;
		} 
	}
	for(int i=0;i<4;i++){
		if(ans[i])cout<<1;
		else cout<<0;
	}
} 
