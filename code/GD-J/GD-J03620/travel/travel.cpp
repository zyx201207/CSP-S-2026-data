#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,ai,b,bi;
	cin>>a>>ai>>b>>bi;
	int k=0;
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]){//是否在同车厢 
		 	cout<<"0000";
		 	return 0;
			k=1; 
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++){
		if(ai[i]!=bi[i]){//是否在同一排 
		 	cout<<"000";
		 	return 0;
		}
	}
	cout<<"1";
	if((ai[2]<'D'&&bi[2]>='D')||(ai[2]>='D'&&bi[2]<'D')){
	 	cout<<"00";
	 	return 0;
	}
	cout<<'1';
	if(ai[2]-bi[2]==1||bi[2]-ai[2]==1){
	 	cout<<"1";
	 	return 0;
	}
	cout<<'0';
	
	fclose("travel.in",stdin);
	fclose("travel.out",stdout);
}
