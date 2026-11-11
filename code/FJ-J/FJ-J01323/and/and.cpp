#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N][30],ans=0,k2[30];
bool no[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	k2[0]=1;
	for(int i=1;i<30;i++) k2[i]=k2[i-1]*2;
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		int tim=0;
		while(x){
			a[i][tim++]=x%2;
			x>>=1;
		}
	}
	for(int i=29;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]&&!no[j]) sum++;
		}
		if(sum>=m){
			ans=ans+k2[i];
			for(int j=1;j<=n;j++){
				if(!a[j][i]) no[j]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}
