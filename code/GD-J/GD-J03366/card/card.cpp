#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
vector<int>z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(q--){
		for(int j=n-q-1;j<n;j++){
			z.push_back(a[j]);
			for(int k=n-q-1;k<j;k++){
				if(a[k]==a[j]){
					int p=j-k;
					while(p--)z.pop_back();	
				}
			}
		}
		for(int i=0;i<z.size();i++){
			b[z[i]]++;
		}
		z.clear();
	}
	for(int i=0;i<m;i++)cout<<b[i+1]<<" ";
	return 0;
}
