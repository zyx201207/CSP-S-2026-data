#include<bits/stdc++.h>
using namespace std;
long long c[100008];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m;
	string a="";
	string b="";
	string d="";
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		a=a+b;
	}
	//cout<<a;
	for(int i=0;i<n;i++){
		b="";
		for(int j=0;j<n-i;j++){
			for(int k=0;k<j;k++){
				if(b[j]==b[k]){
					for(int f=0;f<k;f++){
						d[f]=b[f];
					}
					b=d;
				}
			}
			b[j]=a[i+j];
			
		}
	}
	cout<<b;
	return 0;
}
