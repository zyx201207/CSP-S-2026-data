#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100000005];
char c[100000005];
string s;
long long hwc(string b){
	string s1=b;
	long long sum=0;
	reverse(s1.begin(),s1.end());
	for(long long i=0;i<(int)s1.size()/2;i++){
		if(s1[i]!=b[i]){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cout << hwc(s);
	return 0;
}
