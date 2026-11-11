#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], b[500010], c[500010], tmp=-LLONG_MAX, sum=0, ans=0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	sum-=m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>tmp) tmp=a[i];
	}
	for(int i=1; i<=n; i++){
		if(a[i]<tmp){
			sum+=tmp-a[i];
		}
	}
	for(int i=1; i<=n; i++) b[i]=tmp;
	while(sum>0){
		for(int i=1; i<=n; i++){
			if(b[i]!=a[i]){
				b[i]-=1;
				sum-=1;
//				if(sum<=0) break;
			}
		}
	}
	for(int i=1; i<=n; i++){
		c[b[i]]+=1;
//		cout<<b[i]<<endl;
	}
	for(int i=1; i<=1e5+1000; i++){
		if(c[i]>ans) ans=c[i];
	}
//	tmp=LLONG_MAX;
//	for(int i=1; i<=n; i++){
//		if(b[i]<tmp) tmp=b[i];
//	}
//	for(int i=1; i<=n; i++){
//		if(b[i]==51964) ans++;
//	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
