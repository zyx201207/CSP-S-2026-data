#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum=sum+a[i];
		cin>>b[i];
	}
	long long l=1;
	long long r=sum;
	long long l1=1;
	long long r1=n;
	long long num=0;
	while(l<=r){
		if(b[l1]==b[r1]){
			if(a[l1]<=a[r1]){
				l=l+a[l1];
				r=r-a[l1];
				a[r1]=a[r1]-a[l1];
				l1++;
			}
			else{
				l=l+a[r1];
				r=r-a[r1];
				a[l1]=a[l1]-a[r1];
				r1--;
			}
		}
		else{
			if(a[l1]<=a[r1]){
				l=l+a[l1];
				r=r-a[l1];
				num=num+a[l1];
				a[r1]=a[r1]-a[l1];
				l1++;
			}
			else{
				l=l+a[r1];
				r=r-a[r1];
				num=num+a[r1];
				a[l1]=a[l1]-a[r1];
				r1--;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
	
