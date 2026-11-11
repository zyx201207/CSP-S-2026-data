#include<bits/stdc++.h>
using namespace std;
int t[300005],y[300005],a[500005];
bool x[300005];
int main(){
	ios::sync_with_stdio(0);
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
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0){
				x[a[j]]=1;
				y[a[j]]=j;
			}else{
				for(int k=y[a[j]];k++;k<j){
					if(y[a[j]]==0) break;
					x[a[k]]=0;
					y[a[k]]=0;
				}
				x[a[j]]=1;
				y[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(x[j]==1) t[j]++;
			x[j]=0;
			y[j]=0;
		}
	}
	for(int i=1;i<=m;i++){ 
		cout<<t[i]<<" ";
	}
	return 0;
} 
