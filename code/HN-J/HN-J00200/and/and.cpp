#include<bits/stdc++.h>
using namespace std;
#define int long long
int N=2147483648;
int n,m,k=1,cnt2,c,ans;
int a[200005][35];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	cnt2=n;
	c=0;
	for(int i=1;i<=31;i++){
		N=N/2;
		int cnt=0;
		for(int j=1;j<=cnt2;j++){
			//cout<<(N&a[j][c])<<"\n";
			if((N&a[j][c])>0){
				
				cnt++;
				a[cnt][i]=a[j][c];
			}
		}
		
		if(cnt>=m){
			ans+=N;
			cnt2=cnt;
			c=i;
		}
	}
	cout<<ans;
} 
