#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t;
ll n,d;
ll a[N];
int nex[N];
int b[N];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld %lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)nex[i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int tnt=0;
		for(int i=1;i<=n;i++){
			while(a[tnt+1]-a[i]<=d&&tnt<n)tnt++;
			nex[i]=tnt;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[j]=0;
			}
			b[nex[i]]=3;
			for(int j=i;j<=n;j++){
				if(b[j]==3){
					b[nex[j]]=3;
					for(int k=nex[j-2]+1;k<=nex[j-1];k++){
						b[k]=2;
					}
				}
				else if(b[j]==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
