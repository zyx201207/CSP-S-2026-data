#include<bits/stdc++.h>
using namespace std;
bool isnd(string a){
	long long i=0;
	long long j=a.size()-1;
	while(i<j){
		if(a[i]!=a[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
long long cuo(string s){
	long long i=0;
	long long j=s.size()-1;
	long long sum=0;
	while(i<j){
		if(s[i]!=s[j]){
			sum++;
		}
		i++;
		j--;
	}
	return sum;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[1005];
	char b[1005];
	string s;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++){
			s.push_back(b[i]);
		}
	}
	long long sum=0;
	while(1){
		if(isnd(s)==true){
			cout<<sum;
			return 0;
		}
		else{
			sum=cuo(s);
			break;
		}
	}
	cout<<sum;
	return 0;
}
