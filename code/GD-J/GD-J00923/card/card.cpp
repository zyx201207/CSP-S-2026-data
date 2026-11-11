#include<bits/stdc++.h>
using namespace std;
#define int long long
string v[33][200005];
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> b[35];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		int c=a;
		int cnt=0;
		while(a>0){
			if(a%2==1){
				b[cnt].push_back(c);
			}
			cnt++;
			a/=2;
		}
	}
	int ans=0;
	vector<int> g;
	int sum=0;
	for(int i=30;i>=0;i--){
		if(b[i].size()>=m){
			for(int j:b[i]){
				g.push_back(j);
			}
			sum=i;
			break;
		} 
	} 
	int k=0;
	for(int i:g){
		int s=i;
		k++;
		while(s>0){
			if(s%2==1){
				v[1][k]+='1';
			}
			else{
				v[1][k]+='0';
			}
			s/=2;
		}
	}
	int num=1;
	for(int i=1;i<=sum;i++){
		num*=2;
	}
	ans=num;
	num/=2;
	for(int i=sum-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=k;j++){
			if(v[sum-i][j][i]=='1'){
				cnt++;
				v[sum-i+1][cnt]=v[sum-i][j];
			}
		}
		if(cnt>=m){
			ans+=num;
		}
		num/=2;
	}
	cout<<ans;
} 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	} 
}
