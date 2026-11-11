#include<bits/stdc++.h>
using namespace std;
	long long n , sum=0 ,aum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n , sum=0 ,aum=0;
	string x;
	cin >> n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		sum +=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			x +=b[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		if(x[i] != x[(sum-1)-i]){
			x[i]=x[(sum-1)-i];
			aum++;
		}
	}
	cout << aum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
