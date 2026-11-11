#include<bits/stdc++.h>
using namespace std;
int n,d[200005],f;
long long a[200005],sum[200005],ex[200005][26],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<25;j++){
			if(j==c[i+1]-'a'){
				ex[i][j]=ex[i+1][j]+a[i];
			}
			else{
				ex[i][j]=ex[i+1][j];
			}
		}
	}
	d[0]=n+1;
	for(int i=1;sum[i]<=sum[n]/2;i++){
		f++;
		int ltar=sum[n]-sum[i],ll=1,lr=n;
		d[i]=n;
		while(ll<=lr){
			int lmid=(ll+lr)/2;
			if(sum[lmid]<=ltar){
				ll=lmid+1;
			}
			else{
				d[i]=lr;
				lr=lmid-1;
			}
		}
		int rtar=d[i-1]-1,rl=1,rr=n,rans;
		while(rl<=rr){
			int rmid=(rl+rr)/2;
			if(sum[rmid]<=rtar){
				rl=rmid+1;
			}
			else{
				rans=rr;
				rr=rmid-1;
			}
		}
		if(d[i]==rans){
			if(c[i]!=c[d[i]]){
				ans+=(rtar-ltar+1);
			}
		}
		else{
			if(c[i]!=c[d[i]]){
				ans+=(sum[d[i]]-ltar+1);
			}
			if(c[i]!=c[rans]){
				ans+=(rtar-sum[rans-1]);
			}
			ans+=((sum[i]-sum[i-1])-(ex[d[i]+1][c[i]]-ex[rans][c[i]]));
		}
	}
	if(sum[f]!=sum[n]/2){
		int rtar=d[f]-1,rl=1,rr=n,rans;
		while(rl<=rr){
			int rmid=(rl+rr)/2;
			if(sum[rmid]<=rtar){
				rl=rmid+1;
			}
			else{
				rans=rr;
				rr=rmid-1;
			}
		}
		if(f+1!=rans){
			if(c[f+1]!=c[rans]){
				ans+=(rtar-(sum[n]-sum[n]/2));
			}
			ans+=((sum[n]/2-sum[f])-(ex[f+2][c[f+1]]-ex[rans][c[f+1]]));
		}
	}
	cout<<ans;
	return 0;
}
