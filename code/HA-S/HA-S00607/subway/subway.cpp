#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	int n,m,arr[1000],ans=0,d=0;
	cin>>n>>m;
	ans=m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
    while(arr[0]!=arr[1]&&ans>0){
        arr[0]=arr[0]+1;
    	ans--;
}
    while(arr[0]==arr[1]&&arr[1]<=arr[2]&&ans>=2){
    	arr[0]=arr[0]+1;
    	arr[1]=arr[1]+1;
    	ans=ans-2;
	}
    for(int i=0;i<n;i++){
    	if(arr[i]==arr[i+1]||arr[i]==arr[i-1]){
    		d++;
		}
	}
	cout<<d;
	return 0;
}
