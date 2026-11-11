#include<iostream>
struct strit{int n;char ch;}arr[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;std::cin>>n;
	for(int i=1;i<=n;i++){std::cin>>arr[i].n>>arr[i].ch;}
	int l=1,r=n;long long ans=0;
	while(l<r){
		if(arr[l].ch==arr[r].ch){
			if(arr[l].n==arr[r].n){
				l++;r--;
			}else if(arr[l].n<arr[r].n){
				arr[r].n-=arr[l].n;
				l++;
			}else{
				arr[l].n-=arr[r].n;
				r--;
			}
		}else{
			if(arr[l].n==arr[r].n){
				ans+=arr[l].n;l++;r--;
			}else if(arr[l].n<arr[r].n){
				ans+=arr[l].n;
				arr[r].n-=arr[l].n;
				l++;
			}else{
				ans+=arr[r].n;
				arr[l].n-=arr[r].n;
				r--;
			}
		}
	}std::cout<<ans;
return 0;}
