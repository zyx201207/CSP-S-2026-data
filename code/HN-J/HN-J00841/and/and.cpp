#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],bit[200010][32],len,ans;
vector<int> id[32];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=-1;
		int num=a[i];
		while(num>=0){
			++j;
			if(num%2==1){
				id[j].push_back(i);
			}
			num/=2;
			if(num==0) break;
		}
		len=max(len,j);
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans<<endl;
		return 0;
	}
	for(int j=len;j>=0;j--){
		if(id[j].size()<m) continue;
		for(int l=0;l<=id[j].size()-1;l++){
			for(int r=l+1;r<=id[j].size()-1;r++){
				ans=max(ans,a[id[j][l]]&a[id[j][r]]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

