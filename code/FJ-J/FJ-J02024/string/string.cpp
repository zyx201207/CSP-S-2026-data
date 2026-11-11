#include<bits/stdc++.h>
using namespace std;
long long n;
struct c{
	string t;
};
int arr[100000]={};
c arrs[100000]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>arrs[i].t;
	}
	int cnt=1;
	int cnt1=n;
	int he;
	while(cnt<cnt1){
		if(arrs[cnt].t==arrs[cnt1].t){
			if(arr[cnt]>arr[cnt1]){
				arr[cnt]-=arr[cnt1];
				cnt1--;
			}else if(arr[cnt]<arr[cnt1]){
				arr[cnt1]-=arr[cnt];
				cnt++;
			}else{
				cnt++;
				cnt1--;
			}
		}else{
			if(arr[cnt]>arr[cnt1]){
				he+=arr[cnt1];
				arr[cnt]-=arr[cnt1];
				cnt1--;
			}else if(arr[cnt]<arr[cnt1]){
				he+=arr[cnt];
				arr[cnt1]-=arr[cnt];
				cnt++;
			}else{
				he+=arr[cnt];
				cnt++;
				cnt1--;
			}
		}
		
	}
	cout<<he;
	return 0;
}
