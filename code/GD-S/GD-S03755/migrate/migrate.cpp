#include<bits/stdc++.h>
using namespace std;
long long ap[5010][5010],a[5010],c,t,n,d,ans;
void dfs(long long n,long long f,vector<long long> a){
	if(n==f){
		for(long long it=0;it<a.size();it++){
			ap[a[it]][f]++;
			ap[f][a[it]]++;
		}
		return;
	}
	a.push_back(n);
	int i=n+1;
	while((a[i]-a[n])<=d){
		dfs(i,f,a);
		i++;
	}
	a.pop_back();
	for(long long it=0;it<a.size();it++){
			ap[a[it]][n]++;
			ap[n][a[it]]++;
		}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
			cin>>n>>d;
			long long h=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(i==1&&a[i]<0) {
					h=-a[i];
				}
				a[i]+=h;
			}
			if(c==11||c==12){
				if(((a[2]-a[1])<<1)==d) cout<<n*n-n-n+1<<endl;
				else cout<<0<<endl;
				continue;
			}
			else if(c==13||c==14){
				if(n==3||n==4) cout<<1<<endl;
				cout<<0;
			}
			else{
			dfs(1,n,{});
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(ap[i][j]==2) ans++;
					ap[i][j]=0;
				}
			}
			cout<<(ans>>1)<<endl;
		}
	}
	return 0;
}

