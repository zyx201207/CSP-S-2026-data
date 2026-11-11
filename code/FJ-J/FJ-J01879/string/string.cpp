#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin >> n;
	long long a[n];
	char b[n];
	vector<char> s1,s2;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	long long f=0;
	for(int i=0; i<n; i++){
		for(long long j=0; j<a[i]; j++){
			s1.push_back(b[i]);
			f++;
		}
	}
	f=0;
	for(int i=n-1; i>=0; i--){
		for(long long j=0; j<a[i]; j++){
			s2.push_back(b[i]);
			f++;
		}
	}
	for(long long i=0; i<f/2; i++){
		if(s1[i]!=s2[i])sum++;
	}
	
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
