#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	long long sum=0;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[n+1-i]+sum;
		sum+=a[n+1-i];
	}
	return 0; 
}
