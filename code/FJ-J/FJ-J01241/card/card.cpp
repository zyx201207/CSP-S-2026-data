#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int t[N];
int ans[N];
int la[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	la[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		ans[a[i]]++;
		if(a[i]!=a[n]){
			t[a[i]]++;
		}
		if(!la[a[i]]){
			la[a[i]]=i;
			for(int j=1;j<=m;j++){
				if(t[j]&&j!=a[i]){
					ans[j]++;	
				}
			}
		}
		else{
			for(int j=la[a[i]]-1;j>=i;j--){
				t[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==a[n]){
			cout<<n<<" ";
			continue;
		}
		cout<<ans[i]<<" ";
	}
	return 0;
} 
