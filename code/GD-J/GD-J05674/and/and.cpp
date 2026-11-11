#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b,cnt=1,ans;
	cin>>n>>m;
	int a[n+5];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	while(cnt!=0){
		cnt=0;
		for (int i=0;i<n-1;i++){
			if (a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
				cnt++;
			}
		}
	}
	ans=a[0];
	for (int i=1;i<m;i++){
		ans = (ans & a[i]);
	}
	cout<<ans;
} 
