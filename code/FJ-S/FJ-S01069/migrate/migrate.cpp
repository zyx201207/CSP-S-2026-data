#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int C,T;
int n;
ll d,ans;
int x[2000010];

bool check_A(){
	for(int i=3;i<=n;i++){
		if((x[i]-x[i-1])!=(x[i-1]-x[i-2])){
			return false;
		}
	}
	return true;
}

bool check(int l,int r){
	int p=l;
	ll cnt=0,sum=0;
	while(p<=r){
		p++;
		sum+=x[p]-x[p-1];
		if(sum>d){
			sum=0;
			p--;
			cnt++;
		}
		if(p==r){
			break; 
		}
	}
	if(cnt>2)return false;
	return true;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		ans=0ll;
		if(check_A()){
			if((x[2]-x[1])>d){
				printf("0\n");
			}else{
				ll crs=d/(1ll*(x[2]-x[1]));
				if(crs<=n/2){
					int nn=n;
					while(nn>2){
						if((nn-1)%crs!=0){
							ans+=1ll*n-nn+1;
						}
						nn--;
					}
				}else{
					ans=0ll;
				}
				printf("%lld\n",ans);
			}
			continue;
		}else{
			for(int l=1;l<=n;l++){
				for(int r=l+2;r<=n;r++){
					if(check(l,r)){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
