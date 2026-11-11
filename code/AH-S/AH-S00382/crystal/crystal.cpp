#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],c[500010],tmp;
bool bj=1,bj2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	tmp=a[2]-a[1];
	
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=tmp){
			bj2=0;
			
			break;
		}
	}
	if(bj2==1){
		for(int i=tmp;;i+=tmp){
			m-=i;
			if(m<0){
				cout<<ans+1<<endl;
				return 0;
			}
			ans++;
		}
	}
	tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			bj=0;
			break;
		}
	}
	tmp=0;
	if(bj==1){
		for(int i=2;i<=n;i++){
			tmp+=i-1;
			if(m-tmp<0){
				cout<<i-1;
				return 0;
			}
			m-=tmp;
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1]+c[i-1];
	}
	
	
	tmp=m;
	for(int i=1;i<=n;i++){
		int cnt=0;
		tmp=m;
		for(int j=i;j>=1;j--){
			if(tmp<c[i]-c[j]){
				break;
			}
			tmp-=c[i]-c[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
