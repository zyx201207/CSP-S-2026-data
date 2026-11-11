#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n,m;
	vector<long long> num;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	cout<<num[(num.size()-1)/2];
	return 0;
}
