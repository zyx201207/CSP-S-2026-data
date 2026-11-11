#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1;
	string c2[3];
	
	char c3;
	string c4[3];
	string ans[4]="0";
	cin>>c1;
	cin>>c2[1];
	cin>>c3;
	cin>>c4[1];

	


	if(int(c1)==int(c3)){
		ans[0]="1";
	}
	if(c2[1].begin()==c4[1]
	.begin()){
		ans[1]="1";
	}
	if(ans[0]=="1" || ans[1]=="1"){
		ans[2]="1";
	}
	if(ans[2]=="1"){
		ans[3]="1";
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
}
