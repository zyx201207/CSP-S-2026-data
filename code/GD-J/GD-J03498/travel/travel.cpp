#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
string jie[N],pai[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>jie[1]>>pai[1]>>jie[2]>>pai[2];
	if(jie[1]==jie[2]){
		ans+='1';
	}
	else{
		ans+='0';
	}
	if(pai[1][0]==pai[2][0]&&pai[1][1]==pai[2][1]&&ans[0]=='1'){
		ans+='1';
	}
	else{
		ans+='0';
	}
	if(pai[1][2]<='C'&&pai[2][2]<='C'&&ans[1]=='1'){
		ans+='1';
	}
	else{
		if(pai[1][2]>='D'&&pai[2][2]>='D'){
			ans+='1';
		}
		else{
			ans+='0';
		}
	}
	if(ans[2]=='1'&&(pai[1][2]-1==pai[2][2]||pai[1][2]+1==pai[2][2])){
		ans+='1';
	}
	else{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
