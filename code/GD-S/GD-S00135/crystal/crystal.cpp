#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,total,tz;
struct S{
	long long sj,cz;
};
bool cmp(const S&a,const S&b){
	return a.sj<b.sj;
}
vector<S>v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);v.resize(n);
	for(int i=0,temp;i<n;i++){
		scanf("%lld",&v[i].sj);
	}
	if(n>500){
		for(int i=0,ok=1;i<n;i++){
			if(v[i].sj!=v[0].sj)ok=0;
			if(i==n-1&&ok==1){
				printf("%lld",n);
			}
		}sort(v.begin(),v.end(),cmp);
		int sl=v[1].sj-v[0].sj;
		bool issl=1;
		for(int i=0;i<n-1;i++){
			if(sl!=v[i+1].sj-v[i].sj){
				issl=0;
				break;
			}
		}
		if(issl)for(int i=0;;i++){
			total+=sl*i;
			if(total>m){
				printf("%lld",i);
				return 0;
			}
		}
		return 0;
	}sort(v.begin(),v.end(),cmp);
	v.resize(n+5);
	for(int i=0;i<n-1;i++){
		v[i].cz=v[i+1].sj-v[i].sj;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			tz=0,total=0;
			for(int z=i+1,ii=1;z<=j;z++,ii+=1){
				total+=v[z-1].cz*ii;
				if(total>m||z==n-1){
					break;
				}tz=ii+1;
			}
			ans=max(tz,ans);
			if(tz)continue;
		}
	}printf("%lld",ans);
	return 0;
} 
