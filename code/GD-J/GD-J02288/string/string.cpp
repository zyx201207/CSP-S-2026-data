#include<bits/stdc++.h>
using namespace std;
struct A{
	long long s,e;
	char c;
}a[200005];
long long n,ns=0,sum=0,t,ne,i,j,ans,sum1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	i=0,j=n-1;
	cin>>t>>a[0].c;
	a[0].s=0,a[0].e=t-1,sum=t;
	for(int ii=1;ii<n;ii++){
		cin>>t>>a[ii].c;
		a[ii].s=a[ii-1].e+1;
		a[ii].e=a[ii-1].e+t;
		sum+=t;
		//cout<<sum<<' '<<a[i].s<<' '<<a[i].e<<a[i].c<<endl;
	}
	sum1=(sum+1)/2;
	ne=min(a[0].e,sum-a[n-1].s-1);
	while(i<=j){
		ns=a[i].s;
		while(sum-a[j].s-1<=a[i].e){
		    if(a[i].c!=a[j].c) ans+=ne-ns+1;
		    j--;
		    if(i>j) break;
		    ns=ne+1;
		    ne=sum-a[j].s-1;
		    //cout<<ans<<' '<<i<<' '<<j<<' '<<ns<<' '<<ne<<endl;
		}
		if(sum-a[j].s-1>a[i].e){
		    if(a[i].c!=a[j].c) ans+=a[i].e-ns+1;
		    ns=a[i+1].s;
	    }
		i++;
	}
	for(int ii=0;ii<n;ii++)
		if(a[ii].s+1<=sum1&&a[ii].e+1>=sum1)
		    ans-=2*min(sum1-a[ii].s+1,a[ii].e+1-sum1);
	cout<<ans;
	return 0;
} 
