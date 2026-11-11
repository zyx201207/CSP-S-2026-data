#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	vector<char> b(n);
	vector<char> t;
	long long temp=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		temp+=a[i];
		for(int j=0;j<a[i];j++){
			t.push_back(b[i]);
		}
	}
	long long sum=0;
	for(int i=0,j=t.size()-1;i<=j;i++,j--){
		if(t[i]!=t[j]) sum++;
	}
	cout<<sum;
	return 0;
} 
