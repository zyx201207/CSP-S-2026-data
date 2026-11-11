#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef pair<int,int> PII;
const int N=2e6+114;
const int INF=0x3f3f3f3f3f3f3f3f;


int n,d;
int x[N];


	int C,T;
int l[N]={},r[N]={};
void solve1(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	map<PII,int>mp;
	
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int p=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[p]>d){
			p++;
		}
		l[i]=p;
	}
	p=n;
	for(int i=n;i>=1;i--){
		while(x[p]-x[i]>d){
			p--;
		} 
		r[i]=p;
	}
	
	
//	for(int i=1;i<=n;i++){
//		cout<<l[i]<<' ';
//		
//	}cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<r[i]<<' ';
//		
//	}cout<<endl;
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=l[i];j<=r[i];j++){
			if(i==j)continue;
			for(int k=l[j];k<=r[j];k++){
				if(k==i||k==j)continue;
				if(k>=l[i]&&k<=r[i])continue;
				mp[{i,k}]++;
				if(mp[{i,k}]==2){
					ans++;
//					cout<<"+"<<i<<' '<<j<<' '<<k<<endl;
				}
				else if(mp[{i,k}]==3){
					ans--;
//					cout<<"-"<<i<<' '<<j<<' '<<k<<endl;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(mp[{i,j}]==2)cout<<i<<' '<<j<<' '<<mp[{i,j}]<<endl;
//		}
//	}
	cout<<ans/2<<endl;;
}
//void solve2(){
//	map<PII,int>mp;
//	
//	cin>>n>>d;
//	for(int i=1;i<=n;i++){
//		cin>>x[i];
//	}
//	
//	if(n<=3){
//		cout<<0<<endl;
//		return;
//	}
//	int dd=x[2]-x[1];
//	if(d<=2*dd){
//		cout<<0<<endl;
//		return;
//	}
//	if(2*dd<=d&&3*dd>d){
//		cout<<n-3<<endl;
//		return;
//	}
//	
//}




signed main(){
	IOS
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		solve1();
	}
	
	return 0;
}
