#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[100001],zd=1,s,bg;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=2;i<=n;i++){
	int sj=1;
	sum=0;
		for(int j=i-1;j>=1;j--){
		    sum=sum+sum+a[j+1]-a[j];
		    if(sum>m){
		    	break;
			}
			sj++;
	    }
	    if(sj>zd){
	    	zd=sj;
	    	s=a[i];
	    	bg=i;
		}
	}
	cout<<zd;
	return 0;
}
