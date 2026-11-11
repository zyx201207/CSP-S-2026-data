#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0); 
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxx=-114514;
	for(int i=0;i+m<n;i++){
		int ans=a[i];
		for(int j=i;j<i+m;j++){
			ans&=a[j];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
