#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,k,m,ans=-100;
int a[500005];
int ot[500005],sum[500005];
int t1=1,t2=1;
int ott;

bool cmp(int a,int b){
	//if(a>=0&&b>=0) return a>b;
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2) ott=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=ott) t1=0;
		if(t1==1){
			sum[i]=(i)*(i-1);
			sum[i]/=2;
			sum[i]*=ott;
			if(i>=2&&sum[i]>m&&sum[i-1]<=m){
				cout<<i-1;
				return 0;
			}
		}
		ot[i]=a[1]-a[i];
	}
//	cout<<"infish";
	sort(ot+1,ot+1+n,cmp);
	for(i=1;i<=n;i++){
		//cout<<ot[i];
		//ot[i]=a[1]-a[i];
	}	
	for(i=1;i<=n;i++){
		int sum=0,val=0;
		for(j=1;j<=n;j++){
			
			int otval=ot[j]-(a[1]-a[i]);
			if(otval<0) continue;
			//cout<<otval<<" ";
			if(otval==0) sum++;
			//else if(otval<0) break;
			else{
				if(val+otval<=m){
					val+=otval;
					sum++;
				}
			}
		}
		//if(i%100==0)cout<<"OneFInished,"<<double(100.0-i*100.0/n)<<"Remain\n";
		//printf("\n\n\n");
		ans=max(sum,ans);
		//cout<<ans<<' ';
		//for(j=
	}
	cout<<ans;
	return 0;
}
/* 
5 5
1 2 4 8 9
*/
