#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[200001],s1=0,sum=0;
	char c[200001];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		s1+=a[i];
	}
	long long s2=0;
	int q=-1;
	string s;
	for(int i=0;i<s1;i++){
		if(s2-1<i){	
			s2+=a[q+1];
			q++;	
		}
		s[i]=c[q];
		
	}
	for(int i=0;i<s1/2;i++){
		if(s[i]!=s[s1-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
