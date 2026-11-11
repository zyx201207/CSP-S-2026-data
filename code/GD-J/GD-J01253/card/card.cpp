#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> w;
		for(int j=i;j<=n;j++){
			w.push_back(a[j]);
		}
		int has[500005];
		int id=0;
		memset(has,0,sizeof(has));
		for(int j=0;j<w.size();j++){
			if(has[w[j]]==0){
				has[w[j]]=1;
			}
			else{
				id=max(id,j);
				has[w[j]]=1;
				for(int k=0;k<=id-1;k++) has[w[k]]=0;
			}
		}
		for(int j=id;j<w.size();j++){
			cout<<w[j]<<" "<<i<<endl; 
            t[w[j]]++;			
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
}



