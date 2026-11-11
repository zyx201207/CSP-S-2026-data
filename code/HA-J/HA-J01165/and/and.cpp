#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==n)cout<<a[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
for(int i=0;i<n;i++){
	if(m==i)cout<<a[n-i-1];
}
	return 0;
}
