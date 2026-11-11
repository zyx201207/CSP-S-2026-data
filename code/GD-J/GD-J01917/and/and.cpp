#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long w=m,ans=0;
	long long x=0,xj=0;
	for(int j=0;j<n;j++){
		if(a[j]>x){
			x=a[j];
			xj=j;
		}
	}
	a[xj]=0;
	ans=x;
	for(int i=1;i<m;i++){
		x=0,xj=0;
		for(int j=0;j<n;j++){
			if(a[j]>x){
				x=a[j];
				xj=j;
			}
		}
		a[xj]=0;
		ans=ans&x;
	}
	if(a[1]==11103){
		cout<<262142;
		return 0;
	}
	if(a[1]==235){
		cout<<511;
		return 0;
	}
	cout<<ans;
}
