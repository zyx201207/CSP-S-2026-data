#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0,j=n-1;i<=j;){
		if(a[i]>=a[j]){
			if(c[i]!=c[j]) sum+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else{
			if(c[i]!=c[j]) sum+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
	}
	cout<<sum;
	return 0;
}
