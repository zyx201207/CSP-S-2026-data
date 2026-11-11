#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++) cin>>a[i];
	int maxn=-1;
	if(m==n){
		int c=a[0]&a[1];
		for(int i = 2;i < n;i++){
			c=c&a[i];
		}
		maxn=c;
	}
	if(m==1){
		for(int i = 0;i < n;i++){
			if(a[i]>=maxn) maxn=a[i];
		}
	}
	if(m==2){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j < n;j++){
				if(maxn<=a[i]&a[j]) maxn=a[i]&a[j];
			}
		}
	}
	if(m==3){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j < n;j++){
				for(int w = j+1;w<n;w++){
					if(maxn<=a[i]&a[j]&a[w]) maxn=a[i]&a[j]&a[w];
				}
			}
		}
	}
	if(m=n-1){
		int r=a[0]&a[1],l=a[1]&a[2];
		for(int i = 2;i < n-1;i++){
			r=r&a[i];
		}
		for(int i = 3;i < n;i++){
			l=l&a[i];
		}
		maxn=max(r,l);
	}
	cout<<maxn;
	return 0;
}
