#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin >> n;
	string x[n+5],c[n+5];
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	} 
	int numtemp=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			x[numtemp]=c[i];
			numtemp+=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=num/2;i++){
		if(x[i]!=x[num-i+1])
			cnt++;
	} 
	cout<<cnt;
	return 0;
}
