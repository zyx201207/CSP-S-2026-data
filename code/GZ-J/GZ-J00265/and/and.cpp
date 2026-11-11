//GZ-J00265贵阳市第三中学王上清 
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long,long>
long long n;
long long m;
long long c[200005][4];
long long b[]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483646};
void er(long long i,long long k){
	long long r=31,l=1,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(b[mid]==k){
			c[i][1]=k;
	        c[i][2]=mid;
	        c[i][3]=b[mid]-k;
		}
		if(b[mid]>k){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	c[i][1]=k;
	c[i][2]=l;
	c[i][3]=b[l]-k;
}
bool cmp(pair<pair<long long,long long>,long long>g,pair<pair<long long,long long>long long>k){
    if(g.second<k.second)return true;
    else{
    	if(g.second==k.second)return g.first.first>k.first.first;
	}
}
void ji(){
	cin>>n>>m;
	vector<long long>a(n+1);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		er(i,a[i]);
	}
	vector<pair<pair<long long,long long>long long>>d(n+1);
	for(long long i=1;i<=n;i++){
		d.first.first=c[i][1];
		d.first.second=c[i][2];
		d.second=c[i][3];
	}
	long long ans=0;
	sort(d.begin(),d.end(),cmp);
	for(long long i=1;i<=m;i++){
		ans&=d[i].first.first;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		ji();
	}
	return 0;
}
