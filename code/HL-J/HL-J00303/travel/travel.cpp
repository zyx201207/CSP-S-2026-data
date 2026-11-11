#include<bits/stdc++.h>
using namespace std;
    int a[2],d[4],p=1;
    char s[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a[0]>>s[0]>>s[1]>>s[2]>>a[1]>>s[3]>>s[4]>>s[5];
    if(a[0]==a[1]){
    	d[0]=1;
	}else{
		d[0]=0;
		cout<<"0000";
		return 0;
	}
	if(s[0]==s[3]&&s[1]==s[4]&&p==1){
		d[1]=1;
	}else{
		d[1]=0;
		p=0;
		cout<<"1000";
		return 0;
	}
	if(s[2]<=67&&s[5]<=67&&p==1){
		d[2]=1;
	}else if(s[2]>67&&s[5]>67){
		d[2]=1;
	}else{
		d[2]=0;
		p=0;
		cout<<"1100";
		return 0;
	}
	int z=1;
	for(int i=0;i<3;i++){
		if(d[i]==0){
			z=0;
		}
		cout<<d[i];
	}
	int t=0;
	if((s[2]-s[5]==1||s[2]-s[5]==-1)&&p==1){
		t=1;
	}
	if(s[2]=='D'&&s[5]=='F'){
		t=1;
	}
	if(s[2]=='F'&&s[5]=='D'){
		t=1;
	}
	if(z==1&&t==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
