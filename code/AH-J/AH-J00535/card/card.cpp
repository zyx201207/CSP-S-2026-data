#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005];
map<long long,long long> mp;
bool flag=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		long long cnt=1;
		for(int i=2;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				b[cnt]=i-1;
				cnt++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long cc[500005],n1=n;
			for(int i=1;i<=n;i++){
				cc[i]=a[i];
			}
			for(int j=i;j<=n1;j++){
				mp[cc[j]]++,b[cc[j]]++;
				if(mp[cc[j]]==2){
					long long j1=j;
					mp[cc[j1]]--,b[cc[j1]]--;
					while(j1--&&a[j1]!=a[j]){
						mp[cc[j1]]--,b[cc[j1]]--;
					}
					long long x=j-j1;
					for(int k=j+1;k<=n1;k++){
						cc[k-x]=cc[k];
					}
					n1-=x,j-=x;
				}
			}
			mp.clear();
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
		return 0;
	}
	
	return 0;
}
