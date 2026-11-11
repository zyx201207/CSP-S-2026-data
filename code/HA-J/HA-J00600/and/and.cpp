#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	const int N=n;
	int arr[N];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(m==1){
		cout<<arr[n-1];
		return 0;
	}
	int cnt[200]={0};
	int r=0;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			int arr1[200]={0},arr2[200]={0};
			int k=0;
			while(arr[i]!=0){
				arr1[k]=arr[i]%2;
				arr[i]/=2;
				k++;
			}
			int l=0;
			while(arr[j]!=0){
				arr2[l]=arr[j]%2;
				arr[j]/=2;
				l++;
			}
			int arr3[200]={0};
			for(int p=0;p<max(l,k);p++){
				if(arr1[p]==1&&arr2[p]==1){
					arr3[p]=1;
				}else arr3[p]=0;
			}
			for(int q=0;q<max(l,k);q++){	
				cnt[r]+=pow(2,q)*arr3[q];
			}
			r++;
		}
	}
	sort(cnt,cnt+200);
	cout<<cnt[200];
	return 0;
}