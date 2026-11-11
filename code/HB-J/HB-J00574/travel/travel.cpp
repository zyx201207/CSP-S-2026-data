#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel2.in","r",stdin);
	freopen("travel2.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt=0,f1=0,f2=0,f3=0;
	if(c1==c2){
		cout<<1;
		f1=1;
	}else {
		cout<<0;
	}
	
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i])
			cnt++;
	}
	if(f1&&cnt==2){
		cout<<1;
		f2=1;
	}else {
		cout<<0;
	}
	if(f2&&((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<1;
		f3=1;
	}else{ 
		cout<<0;
	}
	
	if(f3&&abs(s1[2]-s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
