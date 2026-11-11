#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==m){
		int t=a[0];
		for(int i=1;i<n;i++)t=t&&a[i];
		cout<<t;
		return 0;
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int t=a[i]&&a[j];
				maxn=max(maxn,t);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int maxn=-1;
		for(int i=0;i<n;i++){
			int t;
			if(i==0)t=a[1];
			else t=a[0];
			for(int j=0;j<n;j++)
			if(j!=i)t=t&&a[j];
			maxn=max(maxn,t);
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}

