#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n; 
	cin>>n;
	long long s=0;
	long long sum=0; 
	long long l=0;
	vector<pair<long long,char>>xl(n);
	for(int i=0;i<n;i++){
	cin>>xl[i].first;
	cin>>xl[i].second;
s=s+xl[i].first;
	}

vector<long long>ll(s-1);
while(l<=s){
	for(long long i=0;i<n;i++){
	for(long long j=0;j<xl[i].first;j++){
		ll[l]=xl[i].second;
		l++;
	}}
}
for(long long i=0;i<n;i++){
if(ll[i]!=ll[s-i-1]){
	sum++;
	ll[s-i-1]=ll[i];
}
}
cout<<sum;
	
		return 0;
}
