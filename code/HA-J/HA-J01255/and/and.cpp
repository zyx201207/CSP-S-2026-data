#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	int b[100005];
	int w=0;
	int num;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1;a+n+1);
	for(int i=n;i>=m;i--);{
	    w++;
	    b[w]=a[n];
	}
	for(int i=1;i<=w;i++)
	    ans=b[w]&&ans;
	cout<<ans;
	return 0;
}
