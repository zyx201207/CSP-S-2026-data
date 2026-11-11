#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000010],b[2000010],cnt[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,q;
	cin>>c>>q;
	if(c==11||c==12){
		while(q--){
			cin>>n>>m;
			for(int i=0;i<n;i++) cin>>a[i];
			if(a[1]<a[0]) swap(a[1],a[0]);
			cout<<n-m/(a[1]-a[0])*2+1<<endl;
		}
	}
	if(c>10) return 0;
	while(q--){
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		int j=0;
		for(int i=0;i<n;i++){
			while(a[0]+m>a[j]&&j<n+1) j++;
			for(int k=i;k<j;k++){
				b[cnt[i]]=k;
				cnt[i]++;
			}
		}
	}
	return 0;
}
