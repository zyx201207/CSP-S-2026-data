#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0;
int a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>ma){
			ma=a[i];
		}
	}
	cout<<ma;
	return 0;
}
