#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0,t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==i){
				cnt++;
				t=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}