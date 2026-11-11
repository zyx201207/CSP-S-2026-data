#include<bits/stdc++.h>
using namespace std;
long long n,m[100005],sum,sum1;
char a[100005],b[100005];
int main(){
	//freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>a[i];
		for(int j=1;j<=m[i];j++){
			b[j]=a[i];
			sum++;
		}
	}
	for(int i=1;i<=n/2;i++){
		if(b[i]!=b[sum-i+1]){
			sum1++;
		}
	}
	cout<<sum1-1;
	return 0;
}
