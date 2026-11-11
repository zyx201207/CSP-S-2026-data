#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
map<int,int> mp,bmp;
int a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]	;
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			bmp[a[j]]++;
			if(bmp[a[j]]>1){
				bmp.clear();
				bmp[a[j]]++;
			}
			//cout<<a[j]<<" "<<bmp[a[j]]<<endl;
		}
		for(auto &p:bmp){
			if(p.second>0){
				mp[p.first]++;
				//cout<<mp[p.first]<<" "<<p.first<<endl;
			}
		}
		bmp.clear();
	}
	mp[a[n]]++;
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}

