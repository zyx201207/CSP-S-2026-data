#include<bits/stdc++.h>
using namespace std;
char a[100001];
long long a1[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,d;
	cin>>n>>m;
	long long a[100001]={0},b[100001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=min(a[i-1],a[i]);
		d=max(b[i],b[i+1]);
	}
	cout<<d;
	return 0;
}

