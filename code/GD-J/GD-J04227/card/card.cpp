#include <bits/stdc++.h>
using namespace std;
long long q[20000000],l=1,r=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;cin >> n >> m;
	long long a[n+10]{};
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	vector<long long> ans[m+10]{};
	for(int i=1;i<=n;i++){
//		bool ok[m+10]{};
		long tp[m+10]{}; 
		for(int j=i;j<=n;j++){
			if(tp[a[j]]!=0){
				l=tp[a[j]];
			}else{
				q[++r]=a[j];
			}
		}
		for(int j=l;j<=r;j++)ans[q[j]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=00;j<ans[i].size();i++){
			if(ans[i][j]==i){
				cout << i << endl;
				return 0; 
			}
		}
	}
} 
