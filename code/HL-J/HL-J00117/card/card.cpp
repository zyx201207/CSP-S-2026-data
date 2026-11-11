#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],ans[500010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=b[0];k++){
				if(b[k]==a[j]){
					b[0]=k;
					flag=false;
				}
			}
			if(flag){
				b[0]++;
				b[b[0]]=a[j];
			}
		}
		for(int j=1;j<=b[0];j++){
			ans[b[j]]++;
			b[j]=0;
		}
		b[0]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

