#include<bits/stdc++.h>
using namespace std;
int x[200005][33];
int mo[33];
int inn[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		for(int j=0;j<=30;j++){
			x[i][j]=(a>>j)&1;
			if((a>>j)&1){
				mo[j]++;
			}		
		}
	}
	int flag=0,cnt=0;
	for(int i=30;i>=0;i--){
		if(mo[i]>=m && flag==0){
			for(int j=1;j<=n;j++){
				if(x[j][i]){
					inn[j]=1;
				}
			}
			flag=1;
			cnt+=(1<<i);
		}else if(mo[i]>=m){
			int cnt1=0;
			for(int j=1;j<=n;j++){
				if(inn[j]&&x[j][i]){
					cnt1++;
				}
			}
			if(cnt1>=m){
				cnt+=(1<<i);
				for(int j=1;j<=n;j++){
					if(inn[j]&&x[j][i]==0){
						inn[j]=0;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
