#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,b[N][35],idx[N],ans;//b存索引 
bool a[N][35];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){//没问题 
		int c;
		cin>>c;
		b[i][31] = i;
		for(int j = 0;c;c>>=1,j++){//忘写j++了 
			a[i][j] = c&1;
			
		}
	}
	idx[31] = n;
	for(int i = 30;i>=0;i--){
		int sum = 0;
		for(int j = 1;j<=idx[i+1];j++){
			sum+=a[b[j][i+1]][i];
		}
		if(sum>=m){
			
			ans+=1<<i;
			for(int j = 1;j<=idx[i+1];j++){
				if(a[b[j][i+1]][i]==1){
					b[++idx[i]][i] = b[j][i+1];
				}
			}
		}
		else{ 
			for(int j = 1;j<=idx[i+1];j++){
				b[j][i] = b[j][i+1];
			}
			idx[i] = idx[i+1];
		}
	}
	cout<<ans;
	return 0;
}

