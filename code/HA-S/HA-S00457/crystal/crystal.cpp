#include<bits/stdc++.h>
using namespace std;
int n,mans = 0;
long long m,a[500001],al = 0,pj,m1,a1[500001];
bool B = true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	m1 = m;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		al+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		if(i<=n-2)
			if((a[i+1]-a[i])!=(a[i+2]-a[i+1])){
				B = false;
		}
	}
	if(n<=5000){
		for(int i = 1;i<=n;i++){
			a1[i] = a[i];
		}
		for(int i = 1;i<=n;i++){
			for(int j = i-1;j>0;j--){
				if(a[i]-a[j]<=m){
					m-=(a[i]-a[j]);
					a[j] = a[i];
				}else{
					break;
				}
			}
			int ans = 0;
			for(int j = 1;j<=n;j++){
				if(a[j]==a[i]){
					ans++;
				}
			}
			mans = max(mans,ans);
			for(int j = 1;j<=n;j++){
				a[j] = a1[j];
			}
			m = m1;
		}
		printf("%d",mans);
		return 0;	
	}
	if(B==true){
		int sub = a[2]-a[1];
		for(int i = n-1;i;i--){
			if(m>=1LL*(a[n]-a[i])){
				m-=1LL*(a[n]-a[i]);
				a[i] = a[n];
			}
			else
				break;
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			if(a[i] == a[n]){
				ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	pj = al/n;
	int n1 = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]>pj){
			n1 = i-1;
			break;
		}
	}
	int ans = 0;
	for(int i = n1;i>0;i--){
		if(m>=a[n1]-a[i]){
			m-=(a[n1]-a[i]);
			a[i] = a[n1];
		}else{
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		if(a[i]==a[n1]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
