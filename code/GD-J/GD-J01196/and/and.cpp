#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,can[N],ans;
char nums[N][32];
void init(){
	for(int i=1;i<=n;i++)for(int j=0;j<32;j++)nums[i][j]='0';
	return ;
}
void changeToTheCharArray(int x,int ix){
	int power=0;
	while(x)nums[ix][power]=x%2+'0',power++,x/=2;
	return ;
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		changeToTheCharArray(x,i),can[i]=1;
	}
	for(int k=31;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++)if(nums[i][k]=='1'&&can[i])cnt++;
		if(cnt>=m){
			ans+=1<<k;
			for(int i=1;i<=n;i++)if(nums[i][k]!='1')can[i]=0;
		}
	}
	cout<<ans;
	return 0;
} 
