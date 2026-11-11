#include<bits/stdc++.h>
using namespace std;
vector<char> a;
vector<char> b;
long long n;
long long mid;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long num;
		char x;
		cin>>num>>x;
		mid+=num;
		while(num--){
			a.push_back(x);
		}
	}
	mid=ceil((double)mid/2);
	for(int i=a.size()-1;i>=0;i--){
		b.push_back(a[i]);
	}
	for(int i=0;i<mid;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
