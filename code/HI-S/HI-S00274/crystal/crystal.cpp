#include<bits/stdc++.h>
using namespace std;
long long n,m,ann=1,dcsl=-1,ans2=0,an2=1;
long long a[200005],ans[200005],an[200005],jl[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		if(dcsl!=-2){
			if(i==1) dcsl=a[i]-a[i-1];
			if(i>1) if(a[i]-dcsl!=a[i-1]) dcsl=-2;
		}
	}
	if(dcsl>=0){
		for(long long i=1;i<n;i++){
			ans2=ans2+(a[i]-a[i-1])*i;
			if(ans2<=m) an2++;
			else break;
		}
		cout<<an2<<endl;
		return 0;
	}
	for(long long i=1;i<n;i++){ 
		for(long long j=1;j<=i;j++){
			if(jl[j]==0){
				ans[j]=ans[j]+(a[i]-a[i-1])*(i-j+1);
				if(ans[j]<=m){
					an[j]++;
					ann=max(ann,an[j]);
				}
				else jl[j]=1;
			}
		}	
	}
	cout<<ann+1<<endl;
	return 0;
}
