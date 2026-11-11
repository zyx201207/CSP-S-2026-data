#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int ans[300010],c[500010];
vector<int>a;int v=INT_MAX;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int r=a.size();
			for(int k=0;k<r;k++){
				if(a[k]==c[j]){
					v=k;
					break;
				}
			}for(int k=v;k<r;k++){
				a.pop_back();
			}
			v=INT_MAX;
			a.push_back(c[j]);
		}
		int r=a.size();
		for(int k=0;k<r;k++){
			ans[a[k]]++;
//			cout<<a[k]<<' ';
		}
//		cout<<endl;
		a.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//hello~~~~~

