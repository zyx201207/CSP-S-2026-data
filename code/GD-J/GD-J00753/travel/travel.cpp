#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
bool ans[5];
void solve(){
	for(int i=1;i<=4;i++) ans[i]=false;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		ans[1]=true;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			ans[2]=true;
			if(((s_1[2]<='C')&&(s_2[2]<='C'))||((s_1[2]>'C')&&(s_2[2]>'C'))){
				ans[3]=true;
				if(abs(s_1[2]-s_2[2])==1){
					ans[4]=true;
				}
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<ans[i];
	cout<<endl;
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//travel
