#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxp=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p;
		int t=m;
		while(t){
			for(int j=1;j<=n;j++){
				if(i!=j) p=a[i]&a[j];
			}
			t--;
		}
		maxp=max(p,maxp);
	}
	cout<<maxp;
	return 0;
}
