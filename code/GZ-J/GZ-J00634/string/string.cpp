/*GZ-j00634 ·ë»¸î£*/
#include<bits/stdc++.h> 
using namespace std;
char shu[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,chang=0;
	cin>>n;
	for(int i=1,jie=1;i<=n;i++){
		int x=0;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++,jie++){
			shu[jie]=c;
			chang++;
		}
	}
	int zhong=0,q=0,ans=0;
	if(chang%2==1){
		zhong=chang/2+2;
		q=1;
	}else{
		zhong=chang/2+1;
	}
	if(q==1){
		for(int i=zhong,j=1;i<=chang;i++,j++){
			if(shu[i]!=shu[i-2*j]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=zhong,j=0;i<=chang;i++,j++){
			if(shu[i]!=shu[i-2*j-1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
