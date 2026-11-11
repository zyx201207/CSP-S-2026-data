#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-1,s=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-m-1;i++){
		s=a[i];
		for(int j=i+1;j<i+m;j++){
			s^=a[j];
		}
		if(s>max) max=s;
	}
	cout<<max;
	return 0;
}
