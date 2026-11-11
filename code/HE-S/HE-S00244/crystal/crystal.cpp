#include<bits/stdc++.h>
using namespace std;
long long arr[50001];
long long arr1[50001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cin>>arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];
		int q=i;
		cout<<arr[i]<<' ';
		while(q!=0&&arr[q-1]>arr[q]){
			long long a1=arr[q];
			arr[q]=arr[q-1];
			arr[q-1]=a1;
			q--;
		}
	}
	for(int i=1;i<n;i++){
		arr1[i]=arr[i]-arr[i-1];
	}
	int mx=0;
	for(int i=0;i<n-1;i++){
		int m1=m;
		for(int j=i;j<n;j++){
			m1-=arr1[j]*(j-i);
			if(m1<0){
				mx=max(mx,j-i);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
} 
//Oct31==Dec25?
