#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
int l[N],r[N];
ll x[N];
int l1[N];
void solve(){
	int n;ll d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&x[j]-x[i]<=d)j++;
		j--;r[i]=j;
	}j=n;
	for(int i=n;i>=1;i--){
		while(j>=1&&x[i]-x[j]<=d)j--;
		j++;l[i]=j;
	}int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=i;int c1=0,s=0;
			while(k<j){
				k=r[k];if(k<j)l1[++c1]=k;
			}int c2=c1,c3=c1;
			k=j;
			while(k>i){
				k=l[k];if(k>i)s+=l1[c2]-k;c2--;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--)solve();
}

