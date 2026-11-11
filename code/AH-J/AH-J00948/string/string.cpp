#include<bits/stdc++.h>
using namespace std;
long long int a[200010];
char b[100000010],c;
long long int s1;
long long int n,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(long long int j=s;j<s+a[i];j++){
			b[j]=c;
		}
		s+=a[i];
	}
	for(long long int i=0;i<=s/2;i++){
		if(b[i]!=b[s-1-i]){
			s1++;
		}
	}
	cout<<s1;
	return 0;
}

