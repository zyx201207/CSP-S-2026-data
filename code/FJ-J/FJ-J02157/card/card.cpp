#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005];
vector<int> z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int u=0;
			for(int k:z){
				if(k==a[j]){
					u=1;
				}
				if(u==1){
					z.pop_back();
				}
			}
			z.push_back(a[j]);
		}
		for(int k:z){
			s[k]++;
		}
		z.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	} 
	return 0;
}
