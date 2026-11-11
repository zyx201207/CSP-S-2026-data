#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}
	if(n==m){
		int x=a[1];
		for(int i=1;i<n;i++)
			x=x&a[i+1];
		cout<<x<<endl;
		return 0;
	}
	int maxn2=0; 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			maxn2=max(a[i]&a[j],maxn2);
	cout<<maxn2<<endl;
	return 0;
}
