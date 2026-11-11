#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long arr[n];
	string s[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		cin>>s[i];
	}
	string s1;
	s1.clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i];j++){
			s1+=s[i];
		}
	}
	long long sum=0; 
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-1-i]){
			sum++;
		}
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
