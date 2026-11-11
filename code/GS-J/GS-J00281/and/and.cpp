#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=-2;
int h;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		h=a[0];
		for(int i=0;i<n-1;i++){
			h&=a[i];
		}
		cout<<h;
		return 0;
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
					h=a[i]&a[j];
				//cout<<h<<" ";
				maxn=max(h,maxn);
				//cout<<maxn<<" ";
			}
		}
		cout<<maxn;
	}
	return 0;
}
