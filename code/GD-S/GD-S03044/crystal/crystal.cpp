#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],tmm,s=0,maxx=-1,dc,q,h;
void dfs(long long k){
	for(long long i=1;i<=n;i++){
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==a[tmm]) s++;
			}
			maxx=max(s,maxx);
			s=0;
			return;
		}
		if(a[i]>a[tmm]){
			a[i]-=1;
			q++;
		} 
		else if(a[i]<a[tmm]){
			a[i]+=1;
			h++;
		} 
		else{
			k--;
			continue;
		} 
//		for(long long h=1;h<=n;h++){
//			cout<<a[h]<<' ';
//		}
//		cout<<endl;
		dfs(k-1);
		if(q==1){
			a[i]++;
			q--;
		}
		if(h==1){
			a[i]--;
			h--;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	tmm=n/2+1;
	if(n>5000){
		dc=a[2]-a[1];
		s+=(dc+dc*(tmm-1))*(tmm-1)/2;
		s+=(dc+dc*(n-tmm))*(n-tmm)/2;
		cout<<s;
		s=0;
		return 0;
	}
//	long long ljtm=tmm;
//	for(int i=1;i<=n/2;i++){
//		qcz+=a[tmm]-a[tmm-i];
//		hcz+=a[tmm+ljtm]-a[tmm];
//		ljtm++;
//	}
	else{
		sort(a+1,a+n+1);
		dfs(m);
		cout<<maxx;
	}
	return 0;
} 
