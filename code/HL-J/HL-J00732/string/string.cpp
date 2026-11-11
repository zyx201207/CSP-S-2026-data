#include<bits/stdc++.h>
using namespace std;
int c1,n,sum=0;
char c2;
long double sumn=0;
string s1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2;
		for(int j=1;j<=c1;j++){
			s1[sumn]=c2;
			sumn++;
		}
	}
	for(long double i=0;i<sumn/2;i++){
		if(s1[i]!=s1[sumn-i-1])
		sum++;
	}
	cout<<sum;
	return 0;
}