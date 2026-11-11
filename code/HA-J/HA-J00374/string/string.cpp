#include<bits/stdc++.h>
using namespace std;
long long n,i;
long long arr[1000005];
long long ans=0;
int main(){
	freopen("string.in","r",intin);
	freopen("string.out","w",intout);
	cin>>n;
	i=n;
	while(n--){
		string a,b,c,d;
		cin>>arr[i];
		cin>>arr[n];
		if(arr[i]!=arr[n]){
			ans++;
		}
		
	}
	cout<<ans;
	return 0;
} 

