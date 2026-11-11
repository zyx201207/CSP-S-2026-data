#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
long long minn=9999;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		minn=min(a[i],minn);
	}
	cout<<m<<minn<<n;
	return 0;
}
