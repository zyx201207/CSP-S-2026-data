#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],crd[300005];
vector<int> fnd[300005];
int main(){
	freopen("card.in","r",stdin);//!!!
	freopen("card.out","w",stdout);//!!!
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fnd[a[i]].push_back(i);
	}
	
	for(int i=1;i<=n;i++){
		int maxn=-1;
		for(int j=1;j<=m;j++){
			
			if(fnd[j].back()>=i and fnd[j].size()>=2){
				maxn=max(fnd[j].back(),maxn);
				//cout<<"size: "<<(fnd[j].size()>=2)<<endl;
				//cout<<fnd[j].back()<<" ";
				//cout<<endl<<maxn<<" <-   "<<endl;
			}
		}
		if(maxn==-1){
			maxn=i; 
		} 
		for(int j=maxn;j<=n;j++){
			crd[a[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<crd[i]<<" ";
	}
		
		
		
	return 0;
}
