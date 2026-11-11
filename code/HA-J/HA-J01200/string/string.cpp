#include<bits/stdc++.h>
using namespace std;
long long n,a[15000000],k=1,num=0,q;
char l[120000];
char op[150000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>l[i];
		for(int j=1;j<=a[i];j++){
			op[k]=l[i];
			k++;
		}
	}
	q=k-1;
	for(int i=1;i<q;i++){
		if(op[i]!=op[q]){
			num++;
		}
		q--;
	}
	cout<<num;
	return 0;
}
