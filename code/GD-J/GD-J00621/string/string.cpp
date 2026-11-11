#include <bits/stdc++.h>
using namespace std;
int n; 
int a[200005]={0};
string c[200005]={};
string s;
int num=0;
int main()
{
	freopen('string.in','r',stdin);
	freopen('string.out','w',stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int j=0;j<n;j++){
		for(int z=0;z<a[j];z++){
			s+=c[j];
		}
	}
	num=s.size()/2;
	cout<<num;
	return 0;	
} 
