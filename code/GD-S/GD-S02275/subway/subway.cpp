#include <bits/stdc++.h>
using namespace std;
long long w[100000000];
long long minute[1000000];
struct p{
	long long t,l,x;
}s[100000];
bool comp(long long x,long long y){
	return s[x].l>s[y].l;
}
int main(){
	freopen(subway.in,"r",stdin);
	freopen(subway.out,"w",stdout);
	long long c,n,m,d,q,k,y,z,start,end,cnt,bu;
	bu=1;
	cnt=0;
	z=0;
	y=0;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		if(i==1){
			y=0;
		}
		z=k;
		for(long long j=k+1;i<=y+z;i++){
			cin>>s[j].l>>s[j].t;
			s[j].x=bu;
		}
		y=k;
		bu++;
		sort(s+1,s+y+z+1,comp);
	}
	
	for(long long i=1;i<=q;i++){
		cin>>start>>end;
		cnt+=w[start]+w[end]+s[start].t+s[end].t;
		if(s[start].x==s[end].x){
			minute[i]=cnt;
		}
	}
	for(long long i=1;i<=q;i++){
		cout<<minute[i];
	}
	return 0;
}
