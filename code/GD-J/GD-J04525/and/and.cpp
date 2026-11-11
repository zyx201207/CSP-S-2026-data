#include<bits/stdc++.h>
using namespace std;
long long a;
bool s[40][200001];
long long pl1[40];
bool del[200001];
int n,m;
int spla;
long long ans;
long long ans1=1;
bool cmp(long long c,long long b){
	return c>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		int pla=0;
		while(a>0){
			if(a%2==1){
				s[pla][i]=1;
				pl1[pla]++;
			}
			a/=2;
			pla++;
		}
		spla=max(pla-1,spla);
	}
	for(int i=1;i<=spla;i++) ans1*=2;
	for(int i=spla;i>=0;i--){		
		if(pl1[i]>=m){
			ans+=ans1;
		}
		if(pl1[i]>m){
			for(int j=1;j<=n;j++){
				if(s[i][j]==0&&del[i]==0){
					del[i]=1;
					for(int k=spla;k>=0;k--){
						if(s[k][j]==1){
							s[k][j]=0;
							pl1[k]--;
						}
					}
				}
			}
		}
		ans1/=2;
	}
	cout<<ans;
	return 0;
}
