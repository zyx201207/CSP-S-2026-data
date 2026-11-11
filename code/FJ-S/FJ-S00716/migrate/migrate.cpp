#include<bits/stdc++.h>
using namespace std;
int c,T;long long a[2000005],n,m;
long long f(long long q,long long w){
	int sum=0; 
			for(int i=q;i<w;++i){
				if(a[q]+m>=a[w]&&a[q]<=m)sum++;
			}
			if(sum==0)return f(q,w-(q+w)/2)*f(w-(q+w)/2+1,w);
			else if(sum==2)return 1;else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(c<=15&&c>=14){
			int sum=0; 
			for(int i=1;i<n;++i){
				if(a[i]+m>=a[n])sum++;
			}
			if(sum==2)cout<<"1\n";else cout<<"0\n";
			continue;
		}
		long long sum=0;
		for(int i=1;i<=n;++i){
			for(int j=i+2;j<=n;++j){
				sum+=f(i,j);
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
}
