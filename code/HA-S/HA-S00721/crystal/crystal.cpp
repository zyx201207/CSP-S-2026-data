#include<bits/stdc++.h>
using namespace std;
long long a,b,c,e[10000005],l,k,pp;
struct y{
	long long m,n;
}d[10000005];
bool ccc(y p,y o){
	return p.n<o.n;
}
bool bbb(y p,y o){
	return p.m<o.m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	c=b;
	for(long long i=0;i<a;i++){
		cin>>e[i];
	}
	sort(e,e+a);

	d[0].m=e[0];
	for(long long i=1;i<a;i++){
		d[i].m=e[i];
	}
	pp=0;
	while(c>0){
	for(long long i=1;i<a;i++){
		d[i-1].n=d[i].m-d[i-1].m;
	}
	sort(d-1,d+a-1,ccc);
//		for(long long i=0;i<a;i++){
//			cout<<d[i].n<<' ';
//		}
//			cout<<"\n";
	
	for(long long i=0;i<a;i++){
		if(d[i].n==0){
			continue;
		}
		if(d[i].n==d[i+1].n){
			d[i].m=d[i].n+d[i].m;
		}else{
			d[i].m=d[i].n+d[i].m;
			if(c-d[i].n<0){
				c=0;
			}
			c=c-d[i].n;
			break;
		}
	}
	sort(d-1,d+a-1,bbb);
//	for(long long i=0;i<a;i++){
//			cout<<d[i].m<<' ';
//		}
//			cout<<"\n";
	for(long long i=0;i<a;i++){
		if(d[i].m==d[i+1].m){
			k++;
		}
	}
	l=max(k,l);
	k=0;
}
	cout<<l;
	return 0;
}
