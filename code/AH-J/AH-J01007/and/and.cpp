#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	int minn=99999999;
	int summ=a[1];
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		}
	for(int i=2;i<=n;i++){
		summ=summ&a[i];	
		}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<summ;
		return 0;	
	}
	if(m==n-1){
		summ=maxn;
		for(int i=1;i<=n;i++){
			if(a[i]!=maxn&&a[i]!=minn){
				summ=summ&a[i];
			}else{
				if(a[i]==maxn){
					maxn=0;
					continue;
				}else{
					minn=0;
					continue;
				}
			}
		}
		cout<<summ;
		return 0;
	}
	cout<<summ;
	return 0;
}
