#include<bits/stdc++.h>
using namespace std;
vector<int> veg[500005];
int n,m,a[500005],ans[300005];
int erfen(int val,int s){
    for(int i=0;i<=veg[val].size();i++){
    	if(veg[val][i]>=s)return i;
    }return veg[val].size();
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		veg[a[i]].push_back(i);
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(erfen(a[j],j+1)==veg[a[j]].size()) ans[a[j]]++;
			else {
				j=veg[a[j]][erfen(a[j],j+1)]-1;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
