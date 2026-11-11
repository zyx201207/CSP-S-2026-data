#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],d,cnt;
bool cmp(int a,int b){
	return (a & b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    while(d<n){
		cin>>a[d];
		d++;
	}
	sort(a,a+n-1,cmp);
	d=0;
	while(d<m-1){
		a[d+1]=(a[d] & a[d+1]);
	}
	cout<<(a[m-1] & a[m]);
	return 0;
}
