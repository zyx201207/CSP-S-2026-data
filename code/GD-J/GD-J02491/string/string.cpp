#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long num=s.size(),sum=0;
	long long j=num-1;
	for(long long i=0;i<num/2;i++){
		if(s[i]!=s[j]) sum++;
		j--;
	}
	cout<<sum;
	return 0;
}
