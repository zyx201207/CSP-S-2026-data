#include<bits/stdc++.h>
using namespace std;
long long w,y,c,t,n,d,a[2000005],cn=0,bird,mi,m;
int dg(long long st,long long no,long long endd){
	long long cnt=0;
	if(no==endd&&st==mi)return 1;
	if(st==mi)return 0;
	w=no+1;
	while(a[w+1]-a[no]<=d&&w+1<=endd)w++;
	for(int j=w;j>=no+1;j--){
		cnt+=dg(st+1,j,endd);
		if(cnt>2)return cnt;
	}
	return cnt;
}
bool cmp(long long x,long long y){
	bird=x;
	mi=0;
	while(bird<y){
		m=bird;
		while(a[m+1]-a[bird]<=d&&m+1<=y)m++;
		mi++;
		bird=m;
	}
	if(mi==x-y||mi==1)return false;
	if(dg(0,x,y)==2){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cn=0;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n;i++){
			for(long long j=i+3;j<=n;j++){
				if(cmp(i,j)){
					cn++;
				}
			}
		}
		cout<<cn<<endl;
	}
	return 0; 
}
