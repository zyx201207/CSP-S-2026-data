#include <bits/stdc++.h>
using namespace std;
struct Node{
	int shu;
	char str;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	Node arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].shu>>arr[i].str;
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		if(arr[l].str==arr[r].str){
			if(arr[l].shu==arr[r].shu){
				l++;
				r--;
			}else if(arr[l].shu>arr[r].shu){
				arr[l].shu-=arr[r].shu;
				r--;
			}else{
				arr[r].shu-=arr[l].shu;
				l++;
			}
			continue;
		}
		if(arr[l].shu==arr[r].shu){
			ans+=arr[l].shu;
			l++;
			r--;
		}else if(arr[l].shu>arr[r].shu){
			arr[l].shu-=arr[r].shu;
			ans+=arr[r].shu;
			r--;
		}else{
			arr[r].shu-=arr[l].shu;
			ans+=arr[l].shu;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
