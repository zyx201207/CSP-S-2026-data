#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,biao;
bool find(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long cnt=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		long long biao=d*(d+1)/2;
		for(int c=1;c<=n;c++){
			if(find(a[c]+biao))
			cnt++;
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
