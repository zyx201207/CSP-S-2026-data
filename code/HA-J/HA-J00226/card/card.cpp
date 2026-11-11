#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
int n,m,a[N],b[N],f[N];//b[i]为i位置上的纸牌，f[a[j]]为上一个a[j]的位置
int tongji[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//局数
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		int cnt=i-1;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=j;
				cnt++;
				b[cnt]=a[j];
			}
			else{
				bool bol=0;
				for(int k=i;k<=j;k++){
					if(bol){
						f[b[k]]=0;
					}
					if(b[k]==a[j]){
						cnt=k;
						bol=1;
					}
				}
					
			}
		}
		for(int j=1;j<=cnt;j++){
			tongji[b[j]]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<tongji[i]<<" ";
	}
	return 0;
}
