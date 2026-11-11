#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> v;
	long long sum=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(long long i=0;i<x;i++){
			v.push_back(c);
		}
	}
	long long mid=v.size()/2;
	if(v.size()%2==0){
		for(long long i=0;i<=mid;i++){
			long long k=v.size();
			if(v[i]!=v[k]){
				sum++;
			}
			k--;
		}
	}else{
		for(long long i=0;i<mid+1;i++){
			long long k=v.size();
			if(v[i]!=v[k]){
				sum++;
			}
			k--;
		}
	}
	cout<<sum<<endl;
	return 0;
}
