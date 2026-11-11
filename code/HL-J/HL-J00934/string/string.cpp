#include<bits/stdc++.h>
using namespace std;
vector<char> v;
long long n,a,sum;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++){
			v.push_back(c);
		}
	}
	for(long long i=0;i<v.size()/2;i++){
		long long j=v.size()-i-1;
		if(v[i]!=v[j]){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
} 
//159177