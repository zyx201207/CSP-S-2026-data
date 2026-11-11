#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	char c;
	int len;
}arr[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].len>>arr[i].c; 
	}
	int i=1,j=n;
	ll ans=0;
	while(i<j){
		if(arr[i].c!=arr[j].c){
			if(arr[i].len>arr[j].len){
				ans+=arr[j].len;
				arr[i].len-=arr[j].len;
				j--;
			}else if(arr[i].len<arr[j].len){
				ans+=arr[i].len;
				arr[j].len-=arr[i].len;
				i++;
			}else{
				ans+=arr[i].len;
				i++,j--;
			}
		}
		else i++,j--;
	} 
	cout<<ans;
	return 0;
} 

