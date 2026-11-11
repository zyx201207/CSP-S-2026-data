#include<bits/stdc++.h>
using  namespace std;
int n,m,cnt[300005],a[500005],bj[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bj[a[i]]){
				for(int k=i;k<=j;k++){
					bj[a[j]]=0;
				}
			}
			bj[a[i]]=1;
		}
		for(int k=i;k<=n;k++){
			cnt[a[i]]++;
			bj[a[i]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
	}
	return 0;
}
