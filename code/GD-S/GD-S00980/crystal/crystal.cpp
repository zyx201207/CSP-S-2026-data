#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,cnt,num,v[200000000],p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],ans);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		num+=ans-a[i];
	}
	if(num<=m){
		cout<<n;
	}
	if(m==0){
		for(long long i=1;i<=ans;i++){
			for(int j=1;j<=n;j++){	
				if(a[j]==i){
					v[i]++;	
				}
				cnt=max(v[i],cnt);	
			} 
		}
		cout<<cnt; 
	}	
	return 0;
}
