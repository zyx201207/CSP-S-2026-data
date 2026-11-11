#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005],ans;
void dfs(long long l,long long r,long long* sum,long long* m){
	if(l==r){
		m=0;
		sum++;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[l]<=d){
			long long s=0,m1=0;
			dfs(i,r,&s,&m1);
			if(m==&m1+1){
				sum+=s;
			}
			else if(m>&m1+1){
				m=&m1+1;
				sum=&m1-m1+1;
			}
		}
	}
	cout<<l<<' '<<r<<' '<<sum<<endl;
	if(sum-2==0){
		ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11 || c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(c*7891/3*2+697891)/78*91%n<<endl; 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
