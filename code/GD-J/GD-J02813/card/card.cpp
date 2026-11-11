#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			int _[500005];
		for(int j=i;j<=n;j++){
			_[j]=a[j];
			for(int k=i;k<j;k++){
				if(_[k]==a[j]){
					for(int k1=k;k1<j;k1++){
						_[k1]=0;
					}
				}
			}
		}
		for(int k=1;k<n;k++){
			cnt[_[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
