#include<bits/stdc++.h>
using namespace std;
long long sum[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	string a;
	long long n,sum;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>sum;
		cin>>a;
		for(int j=0;j<sum;j++){
			s+=a;
		}
			
	}
	long long sum1=0,j=s.size()-1;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[j] && i!=j){
			sum1++;
		}
		j--;
	}
	cout<<sum1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
