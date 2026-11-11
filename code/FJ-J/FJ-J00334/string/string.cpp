#include<bits/stdc++.h>
using namespace std;
char a[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int p=0,sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char s;
		cin>>num>>s;
		for(int j=1;j<=num;j++){
			p++;
			a[p]=s;	
		}
	}
	for(int i=1;i<=p;i++){
		if(a[i]!=a[p+1-i]){
			a[p+1-i]=a[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
/*
3
2 a
2 b
1 c


2
2 a
3 a

*/
