#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans;
int arr[200005];

int main(){
	freopen("r","and.in",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(m==1){
		cout<<*max_element(arr+1,arr+n+1);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,arr[i]&arr[j]);
//				auto x=bitset<2> (arr[i]);
//				auto y=bitset<2> (arr[j]);
//				cout<<x<<' '<<y<<endl;
			}
		}
		cout<<ans;
	}else if(m==n-1){
		sort(arr+1,arr+n+1);
		ans=arr[2];
		for(int i=3;i<=n;i++){
			ans&=arr[i];
		}
		cout<<ans;
	}
	else if(m==n){
		ans=arr[1];
		for(int i=2;i<=n;i++){
			ans*=arr[i];
		}
		cout<<ans;
	}else{
		sort(arr+1,arr+n+1);
		cout<<arr[(n+1)/2];
	}
	freopen("w","and.out",stdout);
}
