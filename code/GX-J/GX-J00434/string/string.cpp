#include<bits/stdc++.h>
using namespace std;
int arr[2000005];
char brr[2000005],s[2000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("srting.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>brr[i];
	}
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=arr[i];j++){
			s[len+j] = brr[i];
		}
		len+=arr[i];
	}
	int ans=0;
	for(int i=1;i<=len/2;i++){
		if(s[i] != s[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
