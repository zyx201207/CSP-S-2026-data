#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			a[1]&=a[i];
			cout<<a[1]<<endl;
		}
		cout<<a[1]<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		a[1]&=a[i];
	} 
	cout<<a[1]<<endl;
	return 0;
} 
