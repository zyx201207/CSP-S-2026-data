#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long a[2000010];
int counted=0;
int num=0;
 
void f(int ks,int js,int cnt){
	if(ks==js){
		cnt++;
	}
	int zd=a[ks]+d;
	for(int i=ks;a[i]>=zd;i++){
		f(i,js,cnt);
		if(cnt==2){
			num++;
		}
	}
}
 int t,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		if(d>=a[n]-a[1]){
			cout<<0<<endl;
			break;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f(i,j,0);
			}
		}
		cout<<num;
	}
	return 0;
} 
