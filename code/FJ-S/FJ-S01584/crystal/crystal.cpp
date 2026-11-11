#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],cha[N],an[N],lk[N];
long long m,maxx=0;
bool man=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool b=true;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			b=false;
		}
		cha[i]=a[i]-a[i-1];
	}
	bool bg=true;
	for(int i=1;i<=n;i++){
		if(cha[i]!=cha[1]){
			bg=false;
		}
	}
	
	if(b){//A
		int w=1,ans=1;
		while(1){
			m-=w;
			ans++;
			if(m<=0){
				if(m<0){
					ans--;
				} 
				break;
			}
			m-=w;
			ans++;
			if(m<=0){
				if(m<0){
					ans--;
				} 
				break;
			}
			w++;
		}
		cout<<ans;
		return 0;
	}
	
	if(bg){//B
		int zzz=m/cha[1];
		int w=1,ans=1;
		while(1){
			zzz-=w;
			ans++;
			if(zzz<=0){
				if(zzz<0){
					ans--;
				} 
				break;
			}
			zzz-=w;
			ans++;
			if(zzz<=0){
				if(zzz<0){
					ans--;
				} 
				break;
			}
			w++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int f[n];
		long long kl=0,ans=0,ol=0;
		for(int j=1;j<=n;j++){
			f[j]=abs(a[i]-a[j]);
			ol+=f[j];
		}
		sort(f+1,f+1+n);
		while(1){
			kl++;
			ans+=f[kl];
			if(ans>m){
				//ans-=f[kl];
				break;
			} 
		}
		kl--;
		if(ol>=ans){
			maxx=max(maxx,kl);
			//cout<<kl<<" "<<ans<<" "<<ans-f[kl+1]<<" "<<ol<<" "<<i<<endl;
		}
	}
	cout<<maxx;
	return 0;
}

