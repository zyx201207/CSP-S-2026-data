#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i+1;j--){
			if(a[j]>a[j-1])swap(a[j],a[j-1]);
		}
	}
	int x=a[1],y=a[m],ans=x&y;
	int i=a[m],j=a[m+m-1],ans2=i&j;
	cout<<max(ans,ans2);

	return 0;
}

