#include <bits/stdc++.h>
using namespace std;
char p;
string s; 
int main(){
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a,k=0,l=0,mid,sum=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>p;
		for (int j=0;j<a;j++){
			s[k]=p;
			k++;
		}
		l+=a;
	}
	mid=l/2;
	for (int i=0;i<mid;i++){
		if (s[i]!=s[l-1-i]){
			s[i]=s[l-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
