//GZ-J00297 Ёбндлн 
#include <bits/stdc++.h>
using namespace std;

struct str{
	int k;
	char id;
};
str arr[200004];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].k>>arr[i].id;
	}int index=1;
	while(index<n){
		
		if(arr[index].id!=arr[n].id){
			if(arr[index].k<arr[n].k){
				ans+=arr[index].k;
				arr[n].k-=arr[index].k;
				index++;
			}else if(arr[index].k>arr[n].k){
				ans+=arr[n].k;
				arr[index].k-=arr[n].k;
				n--;
			}else if(arr[index].k==arr[n].k){
				ans+=arr[index].k;
				index++;n--;
			}
		}
		
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

