#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],cnt[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i  =1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int st[100000]={1},r=1;
		for(int j = i;j<=n;j++){
			for(int k = 1;k<=r;k++){
				if(st[k]==a[j]){
					for(int l = k;l<=r;l++){
						st[l]=0;
					}
					r=k;
					break;
				}
			}
			r++;
			st[r]=a[j];
		}
		for(int j = 1;j<=r;j++){
			cnt[st[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

