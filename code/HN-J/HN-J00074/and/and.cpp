#include <iostream>
#include <algorithm>
using namespace std;
int m,n,a[100005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		int q=a[i];
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])==maxn){
				a[i]=0;
				a[j]=0;
				break;
			}
		}
		if(a[i]==0&&q)break;
	}
	for(int i=3;i<=m;i++){
		int maxnn=0;
		for(int j=1;j<=n;j++){
			maxnn=max(maxnn,maxn&a[j]);
		}
		maxn=maxnn;
	}
	cout<<maxn;
	return 0;
}
