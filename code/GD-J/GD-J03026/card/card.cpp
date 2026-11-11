#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
map<int,int> m;
int a[N],b[N]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(m[a[j]]==0){
				m[a[j]]=1;
			}
			else{
				for(int r=j-1;a[r]!=a[j]&&r>0;r--){
					m[a[r]]=0;
				}
			} 
		}
		for(int i=1;i<=k;i++){
			if(m[i]==1){
				b[i]++;
			}
			m[i]=0; 
		}
	}
	for(int i=1;i<=k;i++){
		cout<<b[i]<<" ";
	} 
	return 0;
} 
