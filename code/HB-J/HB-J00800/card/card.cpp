#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],cnt=0;
int sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){//n
		cnt=0;
		for(int i=k;i<=n;i++){//
			bool flag=0;
			for(int j=1;j<=cnt;j++){//cmp
				if(a[i]==b[j]){
					cnt=j;
					flag=1;
					break;
				}
			}
			if(!flag){
				cnt++;
				b[cnt]=a[i];
			}
		}
		for(int i=1;i<=cnt;i++){
			sum[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m){
			cout<<sum[i];
		}
		else{
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}
