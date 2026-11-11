#include<bits/stdc++.h>
using namespace std;
int n,m,a[600005],b[300005],lon;
vector<int> sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		a[i]=-1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==-1){
				sum.push_back(a[j]);
				b[a[j]]=lon;
				lon++;
			}else if(b[a[j]]!=-2){
				for(lon=lon;lon>=b[a[j]];lon--){
					b[a[lon]]=-2;
					sum.erase(sum.end());
				}
				sum.push_back(a[j]);
			}
		}
	}
	for(int i=0;i<lon;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
