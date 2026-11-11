#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	int a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=0;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
} 
