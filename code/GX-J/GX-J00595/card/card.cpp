#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int k,cnt=0;
	int a[100010];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(k==2){
			a[k]=0;
			a[k+1]=0;
		}
	}
	if(n=0&&a[n]==1){
		cnt++;
	}
	cout << cnt;
	return 0;
}
