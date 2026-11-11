#include<bits/stdc++.h>
using namespace std;
char a[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i/=10){
		int k=a[i]%10;
		if(a[1]!=a[i]){
			sum++;
		}
		if(a[2]!=a[i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
