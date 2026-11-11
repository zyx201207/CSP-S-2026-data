#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			int now=a[j];
			if(b[now]==0)b[now]++;
		}
	}
	int end=a[n-1];
	b[end]=n;
	for(int i=1;i<=m;i++) cout<<b[i];
}
