#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	vector<long long>cnt(n+10);
	long long k[n+10],a[n];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cnt[i]=a[i]-cnt[i-1];
		k[cnt[i]]=i;		
	}
	sort(cnt.begin(),cnt.end(),cmp);
	ans=a[k[cnt[0]]];
	for(long long i=0;i<m;i++){
		ans=a[k[cnt[i]]]&ans;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
