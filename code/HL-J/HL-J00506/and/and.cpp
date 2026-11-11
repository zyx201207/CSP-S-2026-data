#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>m;
	int n;
	cin>>n;
	int arr[n]={0};
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	int l[100];
	for(int i=0;i<m;i++)
	for(int j=i;j<m;j++){
		l[i]=arr[i] ^ arr[j];
	}
	int maxIndex=-1;
	for(int i=0;i<=n*n;i++){
		maxIndex=max(maxIndex,l[i]);
	}
	cout<<maxIndex;

	return 0;
}
