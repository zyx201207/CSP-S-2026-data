#include<bits/stdc++.h>
using namespace std;
int num[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,pum=0,o=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char a;
		cin>>m>>a;
		int u=pum;
		pum+=m;
		for(int j=u+1;j<=pum;j++){
			num[j]=a;
		}
	}
	for(int i=1;i<=pum/2;i++){
		if(num[i]!=num[pum+1-i])o++;
	}
	cout<<o;
	return 0;
}
