#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int b;
	char c;
} a[N],l[N],r[N];
int n,m,tl=1,tr=1,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c,m+=a[i].b;
		if(a[i].c==a[i-1].c) a[i-1].b+=a[i].b,i--,n--;
	}
    for(int i=0;i<m/2;tl++) l[tl].c=a[tl].c,l[tl].b=min(m/2-i,a[tl].b),i+=a[tl].b;
    for(int i=0;i<m/2;tr++) r[tr].c=a[n-tr+1].c,r[tr].b=min(m/2-i,a[n-tr+1].b),i+=a[n-tr+1].b;
    for(int i=tl;i>=1;i--) if(l[i].b==0) tl--;
    for(int i=tr;i>=1;i--) if(r[i].b==0) tr--;
    int il=1,ir=1,sum=0;
    while(sum<m/2){
		if(l[il].b==r[ir].b){
			if(l[il].c!=r[ir].c) ans+=l[il].b;
			sum+=l[il].b,il++,ir++;
		}
		else if(l[il].b<r[ir].b){
			if(l[il].c!=r[ir].c) ans+=l[il].b;
			sum+=l[il].b,r[ir].b-=l[il].b,il++;
		}
		else{
			if(l[il].c!=r[ir].c) ans+=r[ir].b;
			sum+=r[ir].b,l[il].b-=r[ir].b,ir++;
		}
	}
	cout<<ans;
    //for(int i=1;i<=tl;i++) cout<<l[i].b<<' '<<l[i].c<<'\n';
    //for(int i=1;i<=tr;i++) cout<<r[i].b<<' '<<r[i].c<<'\n';
    return 0;
}
