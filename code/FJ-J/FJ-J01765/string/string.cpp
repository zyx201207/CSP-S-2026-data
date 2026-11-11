#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long int sum;
int a[20005];
char c[20005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		cnt+=a[i];
	}
	if(cnt%2!=0){
		cnt+=1;
	}
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[n-i]){
			if(a[i]<a[n-i]){
				sum+=a[i];
				if(c[i+1]!=c[n-i-1]){
					sum+=a[i]-a[n-i];
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
