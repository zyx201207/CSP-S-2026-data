#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans,l[1000],biao[35];
map<int,int> f[200005];
bool f1;
vector<int> shu[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	biao[1]=1;
	for(int i=2;i<=30;i++) biao[i]=biao[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=a[i],j=1;
		while(t!=0){
			if(t%2==1) l[j]++,shu[j].push_back(a[i]);
			t/=2;
			j++;
		}
	}
	for(int i=30;i>=1;i--){
		if(l[i]>=m){
			if(!f1){
				int len=shu[i].size();
				for(int j=0;j<len;j++){
					f[i][shu[i][j]]=1;
				}
				f1=1;
				ans+=biao[i];
			}else{
				int cnt=0;
				int len=shu[i].size();
				for(int j=0;j<len;j++){
					if(f[i-1][shu[i][j]]) cnt++,f[i][shu[i][j]]=1;
				}
				len=shu[i-1].size();
				if(cnt>=m){
					ans+=biao[i];
				}else{
					for(int j=0;j<len;j++){
						 f[i][shu[i][j]]=f[i-1][shu[i][j]];
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
