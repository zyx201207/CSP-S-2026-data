#include<bits/stdc++.h>
using namespace std;

long long arr[500005];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	long long a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>arr[i];
	}
	long long ts=1;
	while(b){
		
		if(arr[ts]==arr[ts+1]) ts++;
		for(int i=1;i<=ts;i++){
			
			arr[i]++;
			b--;
			
			
		}
		
		
		
	}long long sum=0;
	for(int i=1;i<=a;i++){
		if(arr[i]==arr[i+1]){
			sum++;
		}
	}
	cout<<sum+1;
	
	
	return 0;
}

