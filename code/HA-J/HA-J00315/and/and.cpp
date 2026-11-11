#include<bits/stdc++.h>
using namespace std;
int a[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int num=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int num=n;
		for(int i=1;i<n;i++){
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
	return 0;
}
