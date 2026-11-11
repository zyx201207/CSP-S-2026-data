#include<bits/stdc++.h>
using namespace std;
bool f[200005];
int n,m;
int cnt,ans;
int p;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	p=1<<29;
	for(int i=1;i<=30;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&p)>0&&!f[j]) cnt++;
		}
		if(cnt>=m){
			ans+=p;
			for(int j=1;j<=n;j++){
				if((a[j]&p)==0) f[j]=true;
			}
		}
		p>>=1;
	}
	cout<<ans;
	return 0;
}
