//GZ-J00258 Ñî³¯º­ 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
int arr[100001];
int sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	sort(arr,arr+n-1);
 	cout<<arr[0];
	
 	return 0;
}

