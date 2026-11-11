#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		int cnt=0;
		while(cnt!=i) cnt++;
		for(int j=cnt;j<=n;j++){
				if(a[j]==i){
						cnt--;
				} cnt++;
		}
		cout<<cnt<<" ";
		
	}
	return 0;
}
