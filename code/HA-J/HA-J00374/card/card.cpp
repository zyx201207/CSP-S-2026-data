#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[1000005];
int main(){
	freopen("card.in","r",intin);
	freopen("card.out","w",intout);
	int ans=0;
	int A=0;
	int B=0;
	cin>>n;
	int i=n;
	while(n--){
		int i=n;
		cin>>arr[n];
		string a,b,c,d;
		if(arr[i]==arr[n]){
			arr[i]=0;
		}
		else{
			ans++;
		}
	}
	n=n--;
	while(n--){
		if(arr[i]==arr[n]){
			arr[i]=0;
		}
		else{
			A++;
		}
	}
	n=n--;
	while(n--){
		if(arr[i]==arr[n]){
			arr[i]=0;
		}
		else{
			B++;
		}
}
	cout<<ans<<" "<<A<<" "<<B;
	return 0;
} 

