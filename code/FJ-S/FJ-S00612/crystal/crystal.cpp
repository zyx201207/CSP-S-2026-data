#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],d[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long o=a[i],num=0,m_=m,p;
		for(int j=1;j<=n;j++){
			d[j]=a[j]-o;
		}
		sort(d+1,d+n+1);
		for(int j=n;j>=0;j--){
			if(d[j]==0){
				for(p=j;p>0&&m_>0;p--){
					m_+=d[p];
					d[p]=0;
					num++;
				}
				break;
			}
		} 
		ans=max(ans,num);
	} 
	cout<<ans;
	return 0;
}
