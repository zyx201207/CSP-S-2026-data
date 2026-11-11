#include <bits/stdc++.h>
using namespace std;
long long int n,m=0,cnt=0,v=0,zifu=0;
int a[1000000];
char b[1000000],c[1000000],d[1000000],e[1000000];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	char zi=b[0];
	for (int i=0;i<n;i++){
		for (int j=0;j<a[i];j++){
			c[m]=b[i];
			m++;
		}
	}
	if (m%2==0){
		for (int i=0;i<m/2;i++){
			d[i]=c[i];
		}
		for (int i=m/2;i<m;i++){
			e[v]=c[i];
			v++;
		}
		for (int i=0;i<m/2;i++){
			if (e[v]!=d[i]){
				cnt++;
			}
			v--;
		}
	}
	if (m%2!=0){
		for (int i=0;i<m/2;i++){
			d[i]=c[i];
		}
		for (int i=m/2+1;i<m;i++){
			e[v]=c[i];
			v++;
		}
		for (int i=0;i<m/2;i++){
			cout<<e[v]<<d[i]<<endl;
			if (e[v]!=d[i]){
				cnt++;
			}
			v--;
		}		
	}
	for (int i=0;i<n;i++){
		if (b[i]==zi){
			zifu++;
		}
	}
	if (zifu==n){
		cout<<0;
		return 0;
	}
	cout<<cnt;
	return 0;
}
