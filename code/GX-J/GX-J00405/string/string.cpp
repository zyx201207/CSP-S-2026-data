#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long n,a[110000],cnt=0;
char c[110000];
int main(){
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	int k=n;
	for(int i=1;i<=n;i++){
		if(a[i]>sum){
			if(c[i]!=c[k]){
				cnt+=a[k];
			}
			break;
		}
		if(a[k]<a[i]){
			if(c[i]!=c[k]) cnt+=a[k];
			a[i]-=a[k];
			k--;
			i--;
			sum-=a[k];
		}
		else if(a[i]<a[k]){
			if(c[i]!=c[k]) cnt+=a[i];
			a[k]-=a[i];
			sum-=a[i];
		}
		else{
			if(c[i]!=c[k]) cnt+=a[i];
			k--;
			sum-=a[i];
		}
	}
	cout<<cnt;
	return 0;
}
