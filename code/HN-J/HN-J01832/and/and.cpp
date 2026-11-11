#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
long long n,m,num;
int a[N];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	num=a[n/2];
	for(long long i=1;i<=m;i++){
		num=num&a[n/2-1];
	}
	cout<<num;
	return 0;
}
