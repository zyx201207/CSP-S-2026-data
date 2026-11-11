#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long t=-1,m1=m;
	for(int i=n;i>=1;i--){
	    long long sum=1;
		for(int j=i-1;j>=1;j--){
		    while(m1>0){
			    m1-=a[i]-a[j];
			    sum++;
			}
		}
		t=max(t,sum);
	}
	cout<<t;
	return 0;
}
