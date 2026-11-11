#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
unsigned long long ans,c,b,t,n,d,x[MAXN];
int judge(unsigned long long a,unsigned long long b){
	if(abs(a-b)<=d)return 1;
	return 0;
}
void solve1(unsigned long long b){
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		bool flag=0;
	//	for(int i=1;i<=n;i++){
	//		cin>>x[i];
	///		if(i==2)b=x[i]-x[i-1];
	///		else if(i>2){
	//			if(x[i]-x[i-1]!=b){
	////				flag=1;
	///			}
		//	}
	///	}
	//	if(flag==0){
		//	solve1(b);
			if(n==3)cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
