#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],cnt[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int js=1;js<=n;js++){
		int ans=0;
		for(int i=js;i<=n;i++){
			bool v=true;
			for(int j=1;j<=ans;j++){
				if(a[i]==b[j]){
					ans=j;
					v=false;
					break;
				}
			}	
			if(v){
				ans++;
				b[ans]=a[i];
			}
		}
		for(int i=1;i<=ans;i++){
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
