#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,sum1,sum2;
char a[1000000010],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>x;
		sum2=sum;
		for(int j=sum2+1;j<=sum2+m;j++){
			sum++;
			a[j]=x;
		}
	}
	sum++;
	for(int i=1;i<=sum>>1;i++){
		if(a[i]!=a[sum-i]){
			sum1++;
		}
	}
	cout<<sum1;
	return 0;
}
//80