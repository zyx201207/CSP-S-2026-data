#include<bits/stdc++.h>
using namespace std;
long long int n,m,cnt,arr[100010],a[100010];
long long int brr[100010][50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(long long int i=n-m+1;i<=n;i++){
		while(arr[i]!=0){
			brr[i-n+m][++a[i-n+m]]=arr[i]%2;
			if(arr[i]%2==1)arr[i]--;
			arr[i]/=2;
		}
	}
	for(long long int i=1;i<m;i++){
		for(int j=max(a[i],a[i+1]);j>=1;j--){
			if(brr[i][j]==1&&brr[i+1][j]==1)brr[i+1][j]=1;
			else brr[i+1][j]=0;
		}
    	a[i]=max(arr[i],arr[i+1]);
	}
	cnt=1,n=0;
	for(long long int j=1;j<=a[m];j++){
		n+=cnt*brr[m][j];
		cnt*=2;
	}
	cout<<n;
	return 0;
}
