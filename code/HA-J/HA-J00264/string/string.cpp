#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
long long a[200009];
char s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long c;
		char b;
		cin>>c;
		a[i]=c;
		cin>>b;
		s[i]=b;
	}
	for(long long i=0,j=n-1;i<=j;){
		if(s[i]-s[j]!=0){
			sum+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			a[j]=0;
			j--;
		}else if(a[i]==a[j]){
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}else{
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
	}
	cout<<sum;
	return 0;
}
