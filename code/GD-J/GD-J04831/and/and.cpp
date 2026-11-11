#include<bits/stdc++.h>
using namespace std;
int n,m,a[214514],answ;
bool erjin[200020][32],taotai[214514];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=a[i],wei=0;
		while(cnt){
			erjin[i][++wei]=cnt%2;
			cnt/=2;
		}
	}
	for(int i=31;i>=1;i--){
		int lookfor=0;
		for(int j=1;j<=n;j++){
			if((erjin[j][i])&&(taotai[j]==0))lookfor++;
		}if(lookfor<m)continue;
		answ+=(1<<(i-1));
		for(int j=1;j<=n;j++){
			if(!erjin[j][i])taotai[j]=1;
		}
	}cout<<answ<<'\n';
	return 0;
} 
