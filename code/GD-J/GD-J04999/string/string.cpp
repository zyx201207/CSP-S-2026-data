#include <bits/stdc++.h>
using namespace std;






int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> a;
	vector<unsigned long long> count;
	for(int i=0;i<n;i++){
		unsigned long long t;
		char t2;
		cin>>t>>t2;
		a.push_back(t2);
		count.push_back(t);
	}
	unsigned long long ans=0;
	for(int i=0;i<n;i++){
		if(a[i]!=a[n-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}











