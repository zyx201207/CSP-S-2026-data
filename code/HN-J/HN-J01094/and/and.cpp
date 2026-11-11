#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,m,a[N];
int maxe;

int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxe=max(maxe,a[i]);
		}
		cout<<maxe;
		return 0;
	}
	if(m==n){
		maxe=a[1];
		for(int i=2;i<=n;i++){
			maxe=maxe&a[i];
		}
		cout<<maxe;
		return 0;
	}
	if(m==n-1){
		int op;
		for(int i=1;i<=n;i++){
			op=a[i];
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				op=op&a[j];
			}
			maxe=max(op,maxe);
		}
	}
	int ans;
	for(int i=1;i<=n;i++){
		ans=a[i];
		for(int j=i+1;j<=i+m+1&&j<=n;j++){
			ans=ans&a[j];
		}
		maxe=max(maxe,ans);
	}
	cout<<maxe;
	return 0;
}

