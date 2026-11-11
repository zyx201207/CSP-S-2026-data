#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[1000001];
	string b[1001];
	for (int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	string s[1001],x[1001];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			s[j]=b[i];
	    } 
	}
	for (int i=n;i>=1;i--){
		for (int j=a[i];j>=1;j--){
			x[j]=b[i];
	    } 
	}
	long long sum=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			if (s[i]!=x[i]){
				sum++;
			}
	    } 
	}
	cout << sum/2;
	return 0;
}
