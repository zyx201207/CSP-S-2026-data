#include<bits/stdc++.h>
using namespace std;


long long n;
long long a[100005];
char c[100005];
string s;
long long cou=0;

long long shu(string s){
	long long sum=0;
	long long l=0;
	long long r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			sum++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	return sum;
	
} 
	

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(long long j=0;j<a[i];j++){
			s+=c[cou];
		}	
		cou++;
	}
	
	cout<<shu(s);
	
	
	
	return 0;
}
