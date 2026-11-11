#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1000050],x;
int mid,l,r;
int main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout); 
cin >> n >> m;
 for(int i=0;i<n;i++) cin >> arr[i];
 for(int i=0;i<n;i++) {
 	for(int j=0;j<n-1;j++){
 		if(arr[j]>arr[j+1]){
 			int x=arr[j];
 			arr[j]=arr[j+1];
 			arr[j+1]=x;
 			
    	}
	 }
 }
 mid=n/2+1;
 l=mid-1;
 r=mid+1;
 int mt=m;
 while(x<m){
 	if(l>0&&arr[l]+x=arr[mid]){
 		mt--;
	 }
	 if(r<=n&&arr[r]+x=arr[mid]){
	 	ans++;
	 	mt-=x;
	 	r++;
	 }
	 else
	 x++;
 }
 cout << ans;
 for(int i=0;i<n;i++) cout << arr[i];
	return 0;
} 
