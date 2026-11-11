#include<bits/stdc++.h> 
using namespace std;
int a[200005];
int t[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int mx=INT_MIN;
	for(int i=m;i<=n;i++){
		int x=2147483647;
		for(int j=i-m+1;j<=i;j++){
			x&=a[j];
		}
		mx=max(mx,x);
	} 
	cout<<mx<<endl;
	return 0;
}
