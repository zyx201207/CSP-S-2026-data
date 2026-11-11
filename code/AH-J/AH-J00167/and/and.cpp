#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,Max=0;
	cin>>n>>m;
	int a[200000];
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int i=0;i<n;i++){
		int cnt=a[i];
		for(int j=0;j<m;j++){
			cnt=cnt&a[i+j];
		}
		if(Max<=cnt){
			Max=cnt;	
		}
	}
	cout<<Max;
	return 0;
}
