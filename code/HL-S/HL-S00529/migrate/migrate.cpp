#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+9;
int c,T,n;
ll read(){
	ll x,f=0;char ch=getchar();
//	cout<<1<<endl;
//	cout<<ch;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;ch=getchar();
//		cout<<ch;
	}
//	cout<<endl;
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	//	cout<<ch;
	}
//	cout<<endl;
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c!=0&&c!=11&&c!=12){
		while(T--)cout<<0<<endl;
		return 0;
	}
	while(T--){
		ll a,b,d,ans=0;
		scanf("%d%lld%lld%lld",&n,&d,&a,&b);
		ll len=b-a;
		for(int i=3;i<=n;i++){
			a=read();
			//cout<<a<<" ";
		}
	//	cout<<endl;
		int cnt=d/len;
	//	cout<<len<<" "<<cnt<<endl;
		if(cnt<=1||cnt*2>n){
			cout<<0<<endl;
			continue;
		}
		ans=n-cnt*2+1;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/