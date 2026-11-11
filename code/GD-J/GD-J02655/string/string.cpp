#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	char ch;
}a[200005];
long long n;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ch;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			long long minx=min(a[l].x,a[r].x);
			sum+=minx;
			a[l].x-=minx;
			a[r].x-=minx;
		}
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
	}
	cout<<sum;
	return 0;
}
