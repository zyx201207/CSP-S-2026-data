#include <bits/stdc++.h>
using namespace std;
long long a[100005],n,m,b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		vector <long long> p;
		p.push_back(0); 
		long long g=0;
		for (int j=i;j<=n;j++){
			for (int k=j-1;k>=i;k--){
				if (a[j]==p[k]&&a[j]>0&&p[k]>0){
					for (int q=j-1-k;q>=0;q--){
						g--;
						p.pop_back();
					}
				}
			}
			p.push_back(a[j]);
			g++;
			
		}
		for (int l=1;l<=g;l++){
			b[p[l]]++;
		}
		
	}
	for (int l1=1;l1<=m;l1++){
			cout<<b[l1]<<" ";
		}
	return 0;
} 
