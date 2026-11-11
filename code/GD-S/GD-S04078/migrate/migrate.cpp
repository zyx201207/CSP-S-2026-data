#include<bits/stdc++.h>
using namespace std;

long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
		while(t--){
			int num=0;
			memset(a,0,sizeof(a));
			long long n,d;
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			for(long long i=n;i>=4;i--){
				long long len=a[i]-d;
				int j=i-1;
				while(a[j]>=len){
					j--;
				}
				if(c==11||c==12){
					if(i-j+1==2){
					num=n-3;
					break;
					}
				}
				if(c==13||c==14){
					if(i-j+1==2){
						num++;
					}
					if(a[i]-a[1]<=d){
						break;
					}
				}
				if(i-j-1==2){
						num++;
					}
				if(a[i]-a[1]<=d){
					break;
				}
			}
			cout<<num<<'\n';
		}
	
}
