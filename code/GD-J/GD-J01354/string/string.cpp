#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int n,m,t,T,a[N],b[N],ans,sum,cnt,cut;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
		ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(cut+a[i]>ans/2){
			t=i;
			break;
		}
		cut+=a[i];
		int x=ans-b[i]+1,y=x-1+a[i];
		int k=lower_bound(b+1,b+1+n,x)-b,k1=lower_bound(b+1,b+1+n,y)-b;
		if(b[k]>=y){
			if(c[k]!=c[i]){
				sum+=a[i];
			}	
		}else{
			cnt=a[i];
			for(int j=k;j<=k1-1;j++){
				if(c[j]==c[i]){
					cnt-=a[j];
				}
			}
			if(c[k1]==c[i]){
				cnt=cnt-a[k1]+b[k1]-y;
			}
			sum+=cnt;
		}
	}
	if(cut==ans/2)cout<<sum;
	else{
		if(ans%2)T=1;
		int x=ans/2+1+T,y=x+ans/2-cut-1; 
		int k1=lower_bound(b+1,b+1+n,y)-b;
		for(int i=k1-1;i>t;i--){
			if(c[i]!=c[t]){			
				sum+=a[i];
			}
		}
		if(c[k1]!=c[t]){
			sum+=y-b[k1-1];
		}
		cout<<sum;
	}
	
	return 0;
}

