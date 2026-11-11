#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long c[200005];
long long n,s,sum;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		char x;
		long long y;
		cin>>y>>x;
		if(x==a[i-1]){
			c[i-1]+=y;
		}else{
			s++;
			a[i]=x;
			c[i]=y;
		}
	}
	if(s==1){
		cout<<0;
		return 0;
	}
	long long p=s/2;
	for(long long i=1;i<=p;i++){
		if(i==p&&a[i]==a[i+1]&&s%2==0){
			break;
		}
		int t=s+1-i;
		if(a[i]==a[t]){
			if(c[i]!=c[t]){
				if(c[i]>c[t]){
					c[t]+=c[i]-c[t];
					sum+=c[i]-c[t];
				}else{
					c[i]+=c[t]-c[i];
					sum+=c[t]-c[i];
				}
			}
		}else{
			if(c[i]>c[t]){
				a[i]=a[t];
				c[i+1]+=c[i]-c[t];
				sum+=c[i];
			}else{
				a[t]=a[i];
				c[t-1]+=c[i]-c[t];
				sum+=c[t];
			}
		}
	}
	cout<<sum;
	return 0;
}
