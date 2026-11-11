#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("string.in","r",stdin);
	fopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	string s="";
	long long num;
	string word;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>num>>word;
		for(long long i = 1;i <= num ;i++){
			s+=word;
		}
	}
	long long sum = 0;
	long long l = 0,r = s.size()-1;
	while(l<r){
		if(s[l] != s[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;

	return 0;
} 
