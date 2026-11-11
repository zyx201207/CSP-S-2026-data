#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d;
long long x[2000010];
int cntf[200010],cntb[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long r=x[2]-x[1];
		bool flag=1;
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]!=r){
				flag=0;
			}
		}
		if(flag){
			if(d<2*r) cout<<"0\n";
			else{
				long long len=2*(d/r);
				if(len>n) cout<<"0\n";
				else cout<<n-len+1<<"\n";
			}
			continue;
		}
		long long ans=0;
		for(int pp=1;pp<=n;pp++){
			int qq=pp;
			while(qq<n&&x[qq+1]-x[qq]<=d) qq++;
			for(int l=pp;l<qq;l++){
				for(int r=l+1;r<=qq;r++){
					long long lst=l;
					cntf[l]=0;
					for(int i=l+1;i<=r;i++){
						if(x[i]-x[lst]<=d) cntf[i]=cntf[lst]+1;
						else{
							lst=i-1;
							cntf[i]=cntf[lst]+1;
						}
					}
					lst=r;
					cntb[r]=0;
					for(int i=r-1;i>=l;i--){
						if(x[lst]-x[i]<=d) cntb[i]=cntb[lst]+1;
						else{
							lst=i+1;
							cntb[i]=cntb[lst]+1;
						}
					}
					long long res=0;
					long long mi=1e15;
					if(x[r]-x[l]<=d) continue;
					for(int i=l+1;i<r;i++){
						if(cntf[i]==-1||cntb[i]==-1) continue;
						if(cntf[i]+cntb[i]<mi){
							res=1;
							mi=cntf[i]+cntb[i];
						}
						else if(cntf[i]+cntb[i]==mi) res++;
					}
			//		cout<<l<<" "<<r<<" "<<mi<<" "<<res<<"\n";
					if(res==2){
						ans++;
					}
				}
			}
			pp=qq;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
0 1
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

*/