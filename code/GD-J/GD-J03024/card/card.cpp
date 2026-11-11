#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		if(a[cnt]==0) a[cnt]++;
	}
	int sum=1;
	for(int i=1;i<=n+1;i++){
		if(a[i]==1){
			cout<<sum<<" ";
			sum++;
		}
		else cout<<0<<" ";
	}
	
	
}
