#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long c,n,m,d,q,w[N],a[N],a1[N],t[N],t1[N],k[3],x,y;
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	cin>>k[1];
	long long h=1;
	while(h!=k[1]){
		cin>>a[h]>>t[h];
		h++;
	}
	h=1;
	cin>>k[2];
	while(h!=k[2]){
		cin>>a1[h]>>t1[h];
		h++;
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		bool f=0,f1=0;
		long long st,et;
		for(long long j=1;j<=k[1];j++){
			if(a[j]==x){
				f=1;
				st=t[j];
			}
			if(a[j]==y){
				f1=1;
				et=t[j];
			}
		}
		if(f==f1){
			if(f==0){
				for(long long j=1;j<=k[2];j++){
					if(a1[j]==x) st=t1[j];
					if(a1[j]==y) et=t1[j];
				}
			}
			cout<<w[x]+st+et+w[y]<<'\n';
		}
		else{
			long long stf,stf1;
			for(long long j=1;j<=k[2];j++){
				for(long long l=1;l<=k[1];l++){
					if(a[l]==a1[j]){
						stf=t[j];
						stf1=t1[l];
					}
				}
				if(a1[j]==x) st=t1[j];
				if(a1[j]==y) et=t1[j];
			}
			cout<<w[x]+st+stf+stf1+et+w[y]<<'\n';
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0) ,cin.tie(0),cout.tie(0);
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}
