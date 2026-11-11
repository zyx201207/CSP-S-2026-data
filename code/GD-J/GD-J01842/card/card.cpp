#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100086],b[100086];
int s[100086];
void cle(int n){
	for(int i=1;i<=n;i++){
		a[i]=-1;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			if(s[a[j]]==0){
				s[a[j]]=j;
			}
			else{
				cle(s[a[j]]);
				s[a[j]]=j;
			}
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			if(b[k]!=-1&&b[k]==i){
				ans++;
				cout<<b[k]<<" ";
			}
		}cout<<endl;
		//cout<<ans<<" ";
	}

		   return 0;
}

