#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001]={},min1=2147483647;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(min1>a[i]){
			min1=a[i];
		}
	}
	cout<<min1;
	return 0;
}
