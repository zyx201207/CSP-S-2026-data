#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int k;
long long m,c[500010];
void lwder(int x){
	long long w=m;
	int ans=0;
	for(int i=n;i>=1;i--){
		if(x<c[i])continue;
		if(x==c[i]){
			ans++;
			continue;
		}
		else if(w>=x-c[i]){
			w-=x-c[i];
			ans++;
		}
	}
	cnt=max(cnt,ans);
}
bool B(){
	k=c[2]-c[1];
	for(int i=3;i<=n;i++){
		if(c[i]-c[i-1]!=k)return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	sort(c+1,c+1+n);
	if(B()==true){
		for(int i=1;i<=n;i++){
			if(m>=i*k)m-=i*k;
			else break;
			cnt++;
		}
		printf("%d",cnt+1);
		return 0;
	}
	for(int i=1;i<n;i++){
		lwder(c[i]);
	}
	printf("%d",cnt);
	return 0;
}
