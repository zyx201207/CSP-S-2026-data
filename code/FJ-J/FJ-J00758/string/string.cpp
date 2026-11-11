#include<bits/stdc++.h>
using namespace std;
long long n,len,mid1,mid2,p1=0,p2=0,ll,rr,da,db,cost=0;
long long l[200005],r[200005];
long long a[200005],sum[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		sum[i]=sum[i-1]+a[i];
		l[i]=sum[i-1]+1;
		r[i]=sum[i];
		//cout<<l[i]<<" "<<r[i]<<'\n';
	}
	mid1=(len+1)>>1;
	if(len%2==0){
		mid2=mid1+1;
	}
	else mid2=mid1;
	//cout<<mid1<<" "<<mid2<<"\n";
	for(int i=1;i<=n;i++){
		if(l[i]<=mid1 and r[i]>=mid2){
			p1=i;
			p2=i;
			break;
		}
		if(r[i]<=mid1 and l[i+1]>=mid2){
			p1=i;
			p2=i+1;
			break;
		}
	}
	cost=0;
	//cout<<p1<<' '<<p2<<"\n";
	ll=mid1,rr=mid2;
	if(c[p1]!=c[p2] and mid1 != mid2)cost++;
	while(p1>=1 and p2<=n and ll>=1 and rr<=len){
		da=ll-l[p1];
		db=r[p2]-rr;
		//cout<<ll<<" "<<rr<<' '<<da<<' '<<db<<" ";
		if(da>db){
			if(c[p1]!=c[p2]){
				cost+=db;
			}
			ll=ll-db;
			rr=rr+db;
			p2++;
		}
		else if(da<db){
			if(c[p1]!=c[p2]){
				cost+=da;
			}
			ll=ll-da;
			rr=rr+da;
			p1--;
		}
		else{
			if(c[p1]!=c[p2]){
				cost+=db;
			}
			ll=ll-db;
			rr=rr+db;
			p2++;
			p1--;
		}
		//cout<<ll<<" "<<rr<<"\n";
	}
	cout<<cost<<"\n";
	return 0;
}

