#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int c,t,n;
long long d;
long long ild[2000005];
//bool vis[2000005];
//int ans[1e5+5];
int ans;
int m;
bool warn;
bool yes[500005];

//void check(int x){
//	if j
//}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int zz=0;zz<t;zz++){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<endl;
			break;
		} 
		for(int i=0;i<n;i++){
			cin>>ild[i];
		}
		for(int i=0;i<n-2;i++){
			if(ild[i+1]-ild[i]<d && ild[i+2]-ild[i]<d){
				yes[i]=true;ans++;
			}
		}
		/*for(int i=0;i<n-4;i++){
			if(!yes[i])continue;
			for(int j=i+3;j<n;j++){
				check(j);
			}
		}*/
		cout<<ans<<endl;
	}
	return 0;
}










