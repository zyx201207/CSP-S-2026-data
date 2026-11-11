//²»¿ª longlong ¼û×æ×Ú 
#include<bits/stdc++.h>

using namespace std;

long long m,a[500005],cha[500005],ret=-1,ans;
long long n,j=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	cha[1]=0;
	j=1;
	for(int i=1;i<=n;i++){
		while(ans<=m&&j<n){
			ret=max(ret,(j-i+1));
			ans+=(cha[j]*(j-i+1));
			j++;
		}
		if(ans<=m&&j<=n) ret=max(ret,j-i+1);
//		if(ret!=t) cout<<"arrret="<<ret<<' '<<"ij= "<<i<<' '<<j<<' '<<endl;
		ans-=(a[j]-a[i]);
	}
	cout<<ret<<endl;
	return 0;
}
