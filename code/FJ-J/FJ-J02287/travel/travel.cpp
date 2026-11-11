#include<bits/stdc++.h>
using namespace std;
void mas(){	
	char ans[5]={};
	string ra,xa;
	char rb[5],xb[5];
	// ‰»Î 
	cin>>ra;
	for(int i=1;i<=3;i++)cin>>rb[i];
	cin>>xa;
	for(int i=1;i<=3;i++)cin>>xb[i];
	//≥µœ·	
	if(ra==xa){
		ans[1]='1';
	}else {
		cout<<"0000";
		return ;
	}
	//≈≈ 
	if(rb[1]==xb[1]&&rb[2]==xb[2])ans[2]='1';
		else ans[2]='0';
	//≈≈≤‡ 
	if(ans[2]=='1'){
		if(rb[3]>='A'&&rb[3]<='C'&&xb[3]>='A'&&xb[3]<='C') ans[3]='1';
		else if(rb[3]>='D'&&rb[3]<='F'&&xb[3]>='D'&&xb[3]<='F') ans[3]='1';
		else ans[3]='0';
	}else if(ans[2]=='0')ans[3]='0';
	//œ‡¡⁄ 
	if(ans[3]=='1'&&(rb[3]==xb[3]+1||rb[3]==xb[3]-1))ans[4]='1';
	else if((rb[3]=='D'&&xb[3]=='F')||(rb[3]=='F'&&xb[3]=='D'))ans[4]='1';
	else ans[4]='0';
	// ‰≥ˆ 
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		mas();	
	}
	return 0;	
}
