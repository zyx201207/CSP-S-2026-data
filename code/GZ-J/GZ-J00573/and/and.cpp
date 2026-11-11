//GZ-J00573  遵义市第四初级中学  何雨泽 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr+0,arr+n);
	int s=arr[n-1];
	m--;
	for(int i=n-2;i>=0;i--){
		if(m==0){
			continue;
		}
		else{
			s=s&arr[i];
			m--;
		}
	}
	cout<<s;
	return 0;
}

