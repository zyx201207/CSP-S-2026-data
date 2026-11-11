#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	int s=a[0];
	for(int i=0;i<m;i++) s=s&a[i];
	cout<<s;
	return 0;
}
