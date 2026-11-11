#include<bits/stdc++.h>
using namespace std;
int n,j=0;
long long a,sum=0;
string c;
string s;
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=j;i<a;i++){
			s+=c;
			if(i==a)j=i;
		}
	}
	long long k=s.size();
	long long mid=(k+1)/2;
	for(int i=mid;i<k;i++){
		if(s[i]!=s[k-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
