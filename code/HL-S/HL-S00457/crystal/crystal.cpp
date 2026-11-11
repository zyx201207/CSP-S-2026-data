#include<bits/stdc++.h>
using namespace std;
long long a[780000],b,n,m,ans,ban,ban1,ban_0,ak[780000],akk[780000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(i>0&&a[i]!=a[i-1]+1&&ban==0)ban++;
    	if(i>0&&a[i]!=a[i-1]-1&&ban_0==0)ban_0++;
    	if(i>0&&a[i]!=a[i-1]&&ban1==0)ban1++;
	}
	if(ban==0||ban_0==0){
		if(m>=n){
			cout<<n;
			return 0;
		}
		cout<<m;
		return 0;
	}
	if(ban1==0){
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		long long kkk=a[i]-a[i-1];
		ak[i]=a[i]+ak[i-1];
		akk[i]=kkk+akk[i-1];
		
		cout<<akk[i]<<" "<<ak[i]<<endl;
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<=i;j++){
			if(ak[i]-ak[j]<=m){
				if(ans<=i-j)ans=i-j+1;
				break;
			}
		}
	}
	cout<<ans;
    return 0;
}


