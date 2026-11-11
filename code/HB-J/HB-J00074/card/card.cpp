#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,m,a[500005],book[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=m;j++){
			book[j]++;
			}
	}
	for(int i=1;i<=m;i++){
		cout<<book[i]<<" ";
		}
	return 0;
}
