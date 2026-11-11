#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],va[N],ca[N],anans[N],ans=0;
bool TSA=false,TSB=false;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
////	
	int TSAcnt=1,TSBcnt=1;int dengcha=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==i)TSAcnt++;
		if(a[i+1]-a[i]==dengcha)TSBcnt++;
	}
	if(TSAcnt>=n)TSA=true;
	if(TSBcnt>=n)TSB=true;
	if(TSA==true||TSB==true){
		ans++;
		for(int i=1;i<=m;i++){
			m-=i*dengcha;
			ans++;
			if(m<0)break;
			
		}
		cout<<ans;
	}
	else{
		
	for(int i=n/2;i<=n;i++){
		
		for(int j=1;j<=n;j++){
			if(a[i]>=a[j]){
				va[j]=a[i]-a[j];
				cnt++;
			}
			else{
				va[j]=-1;
			}
		}
//		for(int j=1;j<=n;j++){
//			cout<<va[j]<<" ";
//		}
//		cout<<'\n';

 		sort(va+1,va+n+1);

//		for(int j=1;j<=n;j++){
//			cout<<va[j]<<" ";
//		}
//		cout<<'\n';

		int vlam=m;
		for(int j=1;j<=n;j++){
			if(va[j]>=0){
				vlam-=va[j];
				if(vlam<0) break;
				anans[i]++;
				if(vlam<=0) break;
			}
		}
		cnt=1;
		ans=max(ans,anans[i]);
//		cout<<i<<"."<<anans[i]<<'\n'<<'\n';
	}
	cout<<ans;
	
	
	}
	
	return 0;
}
