#include<bits/stdc++.h>
using namespace std;
long long n,m,v=0,ll,d[1000005],i,j,ans,l, r;
string str,c;
struct node{
	long long m;
	string c; 
}a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		cin>>a[i].m>>a[i].c;
		d[i]=a[i].m;
		ll+=a[i].m;
	}
	for(i=1;i<n;i++)d[i]=d[i-1]+d[i];
	i=0,j=0;
	l=0;
	r=ll;
	while(l<r){
		ans=a[i].m;
		l+=a[i].m;
		while(ans>0&&l<=ll-ll/2&&r>=ll-ll/2){
			if(a[i].c!=a[n-1-j].c&&ans>=a[n-1-j].m){
				v+=a[n-1-j].m;
				r-=a[n-1-j].m;
				ans-=a[n-1-j].m;
				j++;
			}
			else if(ans<a[n-1-j].m&&a[i].c!=a[n-1-j].c){
				v+=ans;
				r-=ans;
				ans=0;
				if(ll-r==d[n]-d[n-j-1])j++;
			}
			else if(a[i].c==a[n-1-j].c&&ans>=a[n-1-j].m){
				r-=a[n-1-j].m;
				ans-=a[n-1-j].m;
				j++;
			}
			else if(ans<a[n-1-j].m&&a[i].c==a[n-1-j].c){
				r-=ans;
				ans=0;
				if(ll-r==d[n]-d[n-j-1])j++;
			}
		}
		i+=1;
	}
	printf("%lld",v);
	return 0;
} 


