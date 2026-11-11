#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b,b1;
	int n,n1,as,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>n1>>b;
		b1="";
		for(int j=1;j<=n1;j++)	b1=b1+b;
		a=a+b1;
	}
	as=a.size();
	for(int i=0,j=as-1;i<j;i++,j--){
		if(a[i]!=a[j]){
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
