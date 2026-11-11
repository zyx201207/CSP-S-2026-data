#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long max=0;
	long long a[200000];
	for(int i=0;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
		
	}
	cout<<max;
}