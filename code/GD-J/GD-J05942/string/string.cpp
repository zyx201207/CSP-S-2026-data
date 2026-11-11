#include<bits/stdc++.h>
using namespace std;
struct kklff{
	long long i;
	char c;
}a[200005];
long long n,m,j=0,ans=0,dikmin;
unsigned long long sum=0;
vector<kklff>d;
int main(){
    freopen("string.in","r",stdin);  
    freopen("string.out","w",stdout);
    cin>>n,a[0].i=-1,a[0].c='A';
    for(long long i=1;i<=n;i++){
    	cin>>a[i].i>>a[i].c,sum+=a[i].i;
    	if(a[i].c==a[i-1].c)d[j-1].i+=a[i].i;
    	else d.push_back(a[i]),j++;
	}
	for(long long i=0,k=j-1,sumpi=0;sumpi<sum;){
	    dikmin=min(d[i].i,d[k].i),d[i].i-=dikmin,d[k].i-=dikmin;
	    if(d[i].c!=d[k].c)ans+=dikmin;
	    i+=(d[i].i==0?1:0),k-=(d[k].i==0?1:0),sumpi+=dikmin*2;
	}
	cout<<ans;
//  cout<<"\n";/*调试用,记得注释掉*/ 
//  for(long long i=0;i<j;i++)cout<<d[i].i<<" "<<d[i].c<<" \n";
    return 0;
}

