#include<bits/stdc++.h>
using namespace std;
long long sum=0,l=0;
char a[200005];
long long n,aa[200005],b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long t=n;
	for(int i=1;i<=n;i++){
		cin>>aa[i]>>a[i];
		l+=aa[i];
	}
	l/=2;
	for(int i=1;l>0;){
		if(a[i]!=a[t]){
			sum+=min(aa[i],aa[t]);
		}
		l-=min(aa[i],aa[t]);
		aa[i]-=min(aa[i],aa[t]);
		aa[t]-=min(aa[i],aa[t]);
		if(aa[i]==0) i++;
		if(aa[t]==0) t++;
	}
	cout<<sum;
}
