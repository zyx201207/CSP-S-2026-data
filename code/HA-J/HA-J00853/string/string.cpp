#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[10000];
	long long n;
	cin>>n;
	int n1[n],x=1,y;
	char n2[n+1],b,m=0;
	for(int i=0;i<n;i++){
		cin>>n1[i]>>n2[i];
	}
	y=n1[0];
	for(int i=0;i<n;i++){
		b=n2[i];
		for(int j=x;j<=y;j++){
			s[j]=b;
		}
		x=y+1;
		y+=n1[i+1];	
	}
	for(int i=1;i<=(strlen(s)-1)/2;i++){
		if(s[i]!=s[strlen(s)-i]){
			m++;
		}
	}
	cout<<m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
