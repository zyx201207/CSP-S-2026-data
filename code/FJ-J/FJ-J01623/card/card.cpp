#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int bj[300005];
int ans[300005];
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			bj[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(bj[a[j]]==0){
				bj[a[j]]=j;
			}else{
				for(int o=bj[a[j]];o<j;o++){
					bj[a[o]]=0;
				}
				bj[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(bj[j]>0){
				ans[j]++;
			}
		}
		/*cout<<"sheyu:";
		for(int j=1;j<=m;j++){
			if(bj[j]>0){
				cout<<j<<" ";
			}
		}
		cout<<endl;*/
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
