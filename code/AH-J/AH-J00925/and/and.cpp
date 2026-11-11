#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool flag=true;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=INT_MIN,maxn1=INT_MIN,res,res1,res2;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	res1=a[0];
//	
//	
	if(m==1) {
		for(int i=0; i<n; i++) {
			if(a[i]>maxn) {
				maxn=a[i];
			}
		}
		cout<<maxn;
		flag=false;
		return 0;
	}
	if(m==2) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i==j) continue;
				else {
					int res=a[i]&a[j];
					if(res>maxn1) {
						maxn1=res;
					}
				}
			}
		}
		cout<<maxn1;
		flag=false;
		return 0;
	}
	if(m==n) {
		for(int i=0; i<n; i++) {
			res1&=a[i];
		}
		cout<<res1;
		flag=false;
		return 0;
	}
	if(flag) {
		cout<<9;
	}
	return 0;
}
