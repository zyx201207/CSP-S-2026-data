#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string a={};
	cin>>n;
	for(int i=0;i<n;i++){
		long long s;
		string s1;
		cin>>s>>s1;
		for(int j=0;j<s;j++){
			a+=s1;
		}
	}
	
	int l=a.size();
	for(int i=0;i<l/2;i++){
		if(a[i]!=a[l-1-i]){
			sum++;				
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
