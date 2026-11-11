#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10; 
int n,m,a[N],tong[N]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		vector<int> kou;
		for(int j=i;j<=n;j++){
			kou.push_back(a[j]);
			int len=kou.size();
			for(int k=len-1;k>=0;k--){
				if(kou[k]==a[j]){
					while(1){
						int ab=kou.size();
						if(ab==k+1) break;
						kou.pop_back(); 
					} 
				}
			} 
		}
		for(int j=0;j<kou.size();j++) tong[kou[j]]++;
	} 
	for(int i=1;i<=m;i++) cout<<tong[i]<<' ';
	return 0;
} 
