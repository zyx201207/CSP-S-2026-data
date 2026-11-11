#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[1010101];
int num[20010][40]={0};
int sum[40];
int fx(int x){
	int sum=1;
	while(x--){
		sum*=2;
	}
	return sum;
}
int v[20010]={0};
void solve(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=32;j>=0;j--){
			if(a[i]>=fx(j)){
				num[i][j]=1;
				a[i]-=fx(i);
			}else{
				num[i][j]=0;
			}
		}
	}
	for(int j=32;j>=0;j--){			
		if(sum[j+1]>=m){
			ans+=fx(j+1);
			for(int i=1;i<=n;i++){
				if(!v[i]&&!num[i][j+1]){
					v[i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(num[i][j]&&!v[i]){
				sum[j]+=1;
			}
		}
		
	}
	if(sum[0]>=m){
		ans+=1;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
/*







ans:0
l:0 r:0
aabbc
aa  c














*/
