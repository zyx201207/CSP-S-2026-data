#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char> a;
	long long N,n,s = 0;
	char b;
	cin>>N;
	int k = 0;
	while(N--){
		cin>>n>>b;
		for(int i = 1;i <= n;i++) a.push_back(b);
	}
	for(int i = 0;i <= a.size() / 2;i++){
		if(a[a.size() - i - 1] != a[i]) s++;
	}
	cout<<s;
	return 0;
}
