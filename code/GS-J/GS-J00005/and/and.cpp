#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);  
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	vector<long long> vec;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	cout<<vec[m-1];
	return 0;
}
