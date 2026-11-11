#include <bits/stdc++.h>
using namespace std;
int n;
char a[200005];
long long x[200005];
long long s,sum=-1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>x[i]>>a[i];
    	sum+=x[i];
	}
	long long sum1=0,sum2=n-1,q1=x[0],q2=x[n-1];
	for (long long i=0,j=sum;i<=j;i++,j--){
		if (i>=q1){
			q1+=x[++sum1];
		}
		if (sum-j>=q2){
			q2+=x[--sum2];
		}
		if (a[sum1]!=a[sum2])  s++;
	}
	cout<<s;
}
