#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int zhuo[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	sort(b+1,b+n+1);
	if(a==b){
		for(int i=1;i<=m;i++){
			cout<<m<<" ";
		}
		return 0;
	}
}

