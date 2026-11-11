#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
int a[101];
int main(){
	freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stringa[1]=a[1]+1;
	for(int i=1;i<=n;i++){
		if(i>m){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
