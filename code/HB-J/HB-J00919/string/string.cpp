#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,sum=0,num;
	int a[10086];
	char b[9178];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		sum+=a[i];
		num+=b[i];
		} 
		if(num%97==0){
			cout << 0;
			return 0;
			}
		if(sum%2==0){
			cout << sum/2;
			}else{
			cout << (sum-1)/2;
			}
	return 0;
}
