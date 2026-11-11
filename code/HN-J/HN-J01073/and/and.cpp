#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
const int N=2e5+5;
int n,m;
bool b[N][33];
int a[N];
int sum[33];
bool fp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		int k=a[i];
		int cnt=0;
		while(k){
			if(k%2)b[i][cnt]=1,sum[cnt]++;
			k/=2;
			cnt++;
		}
	}
	int ans=0;
	int hg=0;
	for(int i=29;i>=0;i--){
		if(sum[i]>=m){
			if(ans==0){
				hg=i;
				ans+=1<<i;
				continue;
			}else {
				int pp=0;
				vector<int >kick;
				rep(j,1,n){
					if(b[j][i]&&b[j][hg]){
						pp++;
					} else if(b[j][hg])kick.push_back(j);
				}
				if(pp>=m){
					ans+=(1<<i);
					for(auto j:kick)b[j][hg]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//贪心。注意到能满足大的位置一定比满足更多的小位置优，O(N*29)处理大位置可以取的数即可 
