#include<bits/stdc++.h>
using namespace std;
int n,m,a[5100001],desk[5100001],len,ans[3100001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		len = 0;
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=len;k++){
				if(desk[k]==a[j]){
					len=k;
					flag=false;
				}
			}
			if(flag){
				len++;
				desk[len]=a[j];
			}
		}
		for(int j=1;j<=len;j++){
			ans[desk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

