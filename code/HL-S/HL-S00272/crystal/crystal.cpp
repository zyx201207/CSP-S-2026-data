#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	s[0]=0;
	for(int i=1;i<n;i++)s[i]=a[i]-a[i-1]+s[i-1];
	long long sum=1,max=0,mn=0;
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(mn+s[i]-s[j]<=m){
				sum++;
				mn+=s[i]-s[j];
				if(sum>max)max=sum;
			}
			else break;
			
		}
		sum=1;
		mn=0;
	}
	cout<<max;
	return 0;
}
