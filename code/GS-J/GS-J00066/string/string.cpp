#include <bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
int a[MAXN];
char b[MAXN];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}

	int i=0,j=n;
	int idx_i=a[i],idx_j=a[j];
	
	while(i<j){
		int t=min(idx_i,idx_j);

		idx_i-=t;
		idx_j-=t;
		if(b[i]!=b[j]){
			ans+=t;
			
		}
		
		if(idx_i<=0){
			idx_i=a[++i];


		}
		if(idx_j<=0){
			idx_j=a[--j];

		}

	}
	
	
	cout<<ans;
	return 0;
}
