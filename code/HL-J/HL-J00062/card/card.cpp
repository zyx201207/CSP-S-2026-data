#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],sum[N];
vector<int> ve;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		ve.clear();
		for(int i=k;i<=n;i++){
			int bj=0;
			for(int j=0;j<ve.size();j++){
				if(bj==1) ve[j]=-1;
				if(ve[j]==a[i]){
					ve[j]=-1;
					bj=1;
				}
			}
			ve.push_back(a[i]);
		}
		for(int i=0;i<ve.size();i++){
			if(ve[i]!=-1){
				sum[ve[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	
	return 0;
}