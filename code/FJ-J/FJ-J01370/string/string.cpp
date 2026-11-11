#include<bits/stdc++.h> 
using namespace std;
int a[100000000000];
char b[100000000000];
string s;
char c[100000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,d=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=d;j<d+a[i];j++){
			c[j]=b[i];
			//cout<<s[j];
		}
		d+=a[i];
	}
	int l=d-1;
	int k=0,s=0;
	while (l>=0){
		if(c[l]!=c[k]){
			s++;	
		}
		l--;
		k++;
	}
	cout<<s/2;
	return 0;
}
