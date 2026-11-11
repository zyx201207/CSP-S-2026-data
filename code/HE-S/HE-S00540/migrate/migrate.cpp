#include<iostream>
using namespace std;
const int MAXN=2*1e6+7;
int L[MAXN],t; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,p;
	cin>>p>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>t;
			L[i]=(i==0?0:L[i-1])+t;
		}
		long long Ans=0;
		for(int st=0;st<n;st++){
			for(int en=st+1;en<n;en++){
				if(L[en]-(st==0?0:L[st-1])<=d)
				Ans++;
			}
		}
		cout<<Ans<<'\n';
	}
	return 0;
} 
