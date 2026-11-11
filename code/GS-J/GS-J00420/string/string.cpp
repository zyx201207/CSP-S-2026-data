#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2;
	long long b=0;
	long long d[100000];
	d[0]=0;
	long long n;
	cin>>n;
	int a[100000];
	char c[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
		int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s1[k]=c[i];
			k++;
		}
	}
	 k=1;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			s2[k]=c[i];
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		b+=a[i];
	}
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=b;j++){
			if(s1[j]==c[i]&&s2[j]!=c[i])d[i]++;
		}
	}
	int q;
	q=d[1];
	for(int i=1;i<=n;i++){
		if(q>d[i]){
			q=d[i];
		}
	}
	cout<<q<<endl;
	return 0; 
}
