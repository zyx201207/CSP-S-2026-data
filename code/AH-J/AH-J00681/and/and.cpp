#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long p[33];
void init(){
	for(int i=1;i<=31;i++){
		p[i]=p[i-1]*2;
	}
}
int a[N],cnt,ans,n,m;
bool flag[N],f1[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	for(int i=31;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			f1[j]=0;
			if(flag[j]&&a[j]>=p[i]){
				a[j]-=p[i];
				f1[j]=true;
				cnt++;
				//cout<<a[j]<<"***";
			}
		}
		//cout<<"   cnt:"<<cnt<<"\n";
		if(cnt<m) continue;
		ans+=p[i];
		//cout<<i<<" "<<p[i]<<" "<<ans<<"\n";
		for(int j=1;j<=n;j++){
			flag[j]=f1[j];
		}
	}
	cout<<ans;
	return 0;
}
