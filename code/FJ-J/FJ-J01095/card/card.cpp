#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
vector<int> b;
int ans[3005],sum[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b.clear();
		for(int j=1;j<=m;j++){
			sum[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(sum[a[j]]){
				while(1){
					int len=b.size();
					if(b[len-1]==a[j]){
						break;
					}else{
						sum[b[len-1]]--;
						b.pop_back();
					}
				}
			}else{
				sum[a[j]]++;
				b.push_back(a[j]);
			}
		}
		for(int j=0;j<(int)b.size();j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
