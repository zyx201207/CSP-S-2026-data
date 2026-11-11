#include<bits/stdc++.h>
using namespace std;
int main(){
	int chex,chey,paix=0,paiy=0,weix,weiy;
	char c;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chex>>c;
	paix+=(c-'0')*10;
	cin>>c;
	paix+=c-'0';
	cin>>c;
	weix=c-'A'+1;
	cin>>chey>>c;
	paiy+=(c-'0')*10;
	cin>>c;
	paiy+=c-'0';
	cin>>c;
	weiy=c-'A'+1;
	if(chex!=chey)cout<<"0000";
	else if(paix!=paiy)cout<<"1000";
	else if(weix<=3&&weiy<=3||weix>=4&&weiy>=4){
		cout<<"111";
		if(abs(weix-weiy)==1)cout<<"1";
		else cout<<"0";
	}else cout<<"1100";
	return 0;
} 
