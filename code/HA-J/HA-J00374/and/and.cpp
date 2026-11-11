#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[1000005];
int main(){
	freopen("and.in","r",intin);
	freopen("and.out","w",intout);
	int ans=0;
	cin>>n;
	int i=n;
	while(n--){
		int i=n;
		cin>>arr[n];
		string a,b,c,d;
		if(arr[i]>=arr[n]&&arr[i]==arr[n]){
			ans=arr[i];
		}
	}
	cout<<ans;
	return 0;
} 

