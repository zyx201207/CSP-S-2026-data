#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out"."w",stdout);
	long long a,b,c;
	cin>>a>>b;
	vector<long long> arr(a);
	for(long long i=0;i<a;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end(),cmp);
	c=arr[0];
	for(long long i=1;i<b;i++){
		c=c&arr[i];
	}
	cout<<c;
	return 0;
}
