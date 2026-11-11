#include<bits/stdc++.h>
using namespace std;
long long n,m,a[610000],ans[410000];
bool s[610000];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
		if(s[a[i]]==0){
			s[a[i]]=1;
		}
		if(s[a[i]]==1){
			for(int j=1;j<=n;j++){
				s[a[j]]=0;
			}
			s[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[a[i]]==1){
			ans[a[i]]++;
		}
	}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
