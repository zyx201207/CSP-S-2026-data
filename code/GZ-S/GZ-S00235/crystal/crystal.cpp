//GZ-S00235 张普博 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,su,k,maxn,t;
long long a[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		k=i+1;
		su=0;
		while(k<=n){
			if(su+a[i]-a[k]<=m){
				su+=a[i]-a[k];
			}
			else{
				k--;
				break;
			}
			k++;
		}
		maxn=max(maxn,k-i);
		if(k-1>=n) break;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
