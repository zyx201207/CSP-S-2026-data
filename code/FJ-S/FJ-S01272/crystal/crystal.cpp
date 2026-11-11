#include<bits/stdc++.h>
using namespace std;
int arr[500009],err[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+a+1);
	arr[0]=0;
	for(long long i=1;i<=a;i++){
		err[i]=arr[i]-arr[i-1];
	}
	long long op=0,cnt=0;
	long long xx=0;
	err[a+1]=INT_MAX; 
	for(long long i=1;i<=a;i++){
		xx=0;
		op=0;
		for(long long j=i;xx<=b;j++){
			xx=xx+xx+err[j];
			if(xx<=b){
				op++;
			}else{
				break;
			}
		}
		if(cnt<op-1){
			cnt=op-1;
		}
	}
	cout<<cnt;
	return 0;
} 
