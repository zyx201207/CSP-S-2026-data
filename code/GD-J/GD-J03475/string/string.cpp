#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF=0x3f3f3f3f;
vector<char>a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	cout<<sum;
	while(n--){
		int len;char c;
		cin>>len>>c;
		sum+=len;
		while(len--)a.push_back(c);
	}

	int cnt=0;
	cout<<sum;
	for(int i=0;i<=sum/2;i++){
		if(a[i]!=a[sum-i])cnt++;
	}
	cout<<cnt;

	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
// 3000000000
