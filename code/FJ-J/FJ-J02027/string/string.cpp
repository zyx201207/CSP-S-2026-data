#include<bits/stdc++.h>
using namespace std;
	ifstream fin("string.in");
	ofstream fout("string.out");
int main(){
	char s[601],m[601];
	long long a[601]={0},p=0,sum=0,l=0,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		l+=a[i];
		while(a[i]>0){
			m[p]=s[i];
			p++;
			a[i]--;
		}
	}
	for(int i=0;i<l;i++){
		if(m[i]!=m[n-i]&&m[i]!=m[n-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
