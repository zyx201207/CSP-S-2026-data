#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,l,r,mid,ans,x[200005],y[200005],cnt,k,f,g;
string c[200005],xz[200005],yz[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	f=sum/2;
	ans=sum/2;
	for(int i=1;i<=n;i++){
		if(cnt<f){
			cnt+=a[i];
			x[i]=a[i];
			xz[i]=c[i];
		}else{
			k++;
			if(cnt>f){
				i--;
				y[k]=cnt-f;
				yz[k]=xz[i];
				x[i]=cnt-f;
				cnt=f;
				continue;
			}
			y[k]=a[i];
			yz[k]=c[i];
		}
	}
	if(sum%2==1){
		y[1]-=1;
	}
	l=1,r=k;
	while(l<=((n+1)/2+1)){
		if(xz[l]==yz[r]){
			ans-=min(x[l],y[r]);
			x[l]-=min(x[l],y[r]);
			y[r]-=min(x[l],y[r]);
			if(x[l]==0){
				l++;
			}
			if(y[r]==0){
				r--;
			}
		}else{
			x[l]-=min(x[l],y[r]);
			y[r]-=min(x[l],y[r]);
			if(x[l]==0){
				l++;
			}
			if(y[r]==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

