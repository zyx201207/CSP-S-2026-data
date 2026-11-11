#include<bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int brr[200005];
 
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	
bool ok=true;
	long long m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i>0)
		brr[i]=abs(abs(arr[i])-abs(arr[i-1]));
	} brr[0]=abs(arr[0]);
	
	int i=0;
//	for(;i<n;i++){
//		cout<<brr[i]<<" ";
//	}
	for(;m-brr[i]>=0;i++){
		m-=brr[i]*(i+1);
	}
	cout<<i;
	
	return 0;
}
