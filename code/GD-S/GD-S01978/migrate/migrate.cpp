#include<bits/stdc++.h>
#define int long long
#define N 2000010
#define len(a,b) (x[b]-x[a]) 
using namespace std;
int c,t,n,d,f[N],k[N],x[N],sk[N],sf[N];

int find(int l,int r){
	if(r<l) return -1;
	int ldi=-1,rdi=-1,nl,nr;
	nl=1,nr=n;
	while(nl<=nr){
		int md=(nl+nr)>>1;
		if(x[md]<=r){
			rdi=md;
			nl=md+1;
		}else{
			nr=md-1;
		}
	}
	nl=1,nr=n;
	while(nl<=nr){
		int md=(nl+nr)>>1;
		if(x[md]>=l){
			ldi=md;
			nr=md-1;
		}else{
			nl=md+1;
		}
	}
	if(ldi==-1||rdi==-1) return 0;
	return rdi-ldi+1;
}

int kksk(int lll){
	return (lll-1)*lll/2;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			f[i]=sf[i]=k[i]=sk[i]=0;
		}
//		cout<<find(x[n]-d,x[1]+d)<<endl;
		for(int i=2;i<=n;i++){
			sk[i]=sk[i-1]+k[i];
			sf[i]=sf[i-1]+f[i];
			int l,r,nw,nowl,nowe,nowr,nowk;
			//<=2d
			l=1,r=i-1,nw=-1;
			while(l<=r){
				int md=(l+r)>>1;
				if(len(md,i)<=2*d){
					nw=md;
					r=md-1;
				}else{
					l=md+1;
				}
			}
			nowk=nw;
			if(len(nowk,i)<=d) nowk=-1;
			//<d
			l=1,r=i-1,nw=-1;
			while(l<=r){
				int md=(l+r)>>1;
				if(len(md,i)>d){
					nw=md;
					l=md+1;
				}else{
					r=md-1;
				}
			}
			nowl=nw;
			if(nowl==-1){
				k[i]=i-1;
				sk[i]=sk[i-1]+k[i];
				sf[i]=sf[i-1]+f[i];
				continue;
			}
			k[i]+=i-nowl-1;
			sk[i]=sk[i-1]+k[i];
			sf[i]=sf[i-1]+f[i];
			l=1,r=nowl;nw=-1;
			while(l<=r){
				int md=(l+r)>>1;
				int now=find(x[i]-d,x[md]+d);
				if(now>=3){
					nw=md;
					r=md-1;
				}else{
					l=md+1;
				}
			}
			nowe=nw;
			l=1,r=nowl;nw=-1;
			while(l<=r){
				int md=(l+r)>>1;
				int now=find(x[i]-d,x[md]+d);
				if(now>=2){
					nw=md;
					r=md-1;
				}else{
					l=md+1;
				}
			}
			nowr=nw;
			if(nw!=-1){
				if(nowe==-1){
					f[i]+=sk[nowl]-sk[nw-1]+(nowl-nw+1)-(nowk!=-1?kksk(nowl-nowk+1)-kksk(nw-nowk):kksk(nowl-nw+1));
				}else{
					f[i]+=sk[nowe-1]-sk[nw-1]+(nowe-nw)-(nowk!=-1?kksk(nowe-nowk)-kksk(nw-nowk):kksk(nowe-nw));
				}
			}
			sk[i]=sk[i-1]+k[i];
			sf[i]=sf[i-1]+f[i];
			l=1,r=nowl;nw=-1;
			while(l<=r){
				int md=(l+r)>>1;
				int now=find(x[i]-d,x[md]+d);
				if(now>=1){
					nw=md;
					r=md-1;
				}else{
					l=md+1;
				}
			}
			if(nw!=-1){
				if(nowr==-1){
					if(nowe==-1){
						k[i]+=sk[nowl]-sk[nw-1];
						f[i]+=sf[nowl]-sf[nw-1];
					}else{
						k[i]+=sk[nowe-1]-sk[nw-1];
						f[i]+=sf[nowe-1]-sf[nw-1];
					}
				}else{
					k[i]+=sk[nowr-1]-sk[nw-1];
					f[i]+=sf[nowr-1]-sf[nw-1];
				}
			}
			sk[i]=sk[i-1]+k[i];
			sf[i]=sf[i-1]+f[i];
//			cout<<sf[i]<<endl;
//			cout<<nw<<' '<<nowr<<' '<<nowe<<' '<<nowl<<' '<<i<<endl;
		}
//		for(int i=1;i<=n;i++){
//			cout<<k[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<' ';
//		}
//		cout<<endl;
		cout<<sf[n]<<'\n';
	}
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
