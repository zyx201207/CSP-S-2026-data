#include<bits/stdc++.h>
using namespace  std;
long long w[1000005];
struct node{
	long long a[500005],t[500005];
}nn[505];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>nn[i].a[j]>>nn[i].t[j];
	}
	while(q--){
		int s,e,ans=0,ss,sss,ee,eee,jj;
		cin>>s>>e;
		ans+=w[s]+w[e];
		for(int i=1;i<n;i++){
			int j=1;
			while(nn[i].a[j]!=0){
				int k=j+1;
				bool flag=false;
				if(nn[i].a[j]==s) ss=i;sss=j;
				if(nn[i].a[j]==e) ee=i;eee=j;
				while(nn[i+1].a[k]!=0){
					if(nn[i].a[j]==nn[i+1].a[k]){
						jj=i;
						flag=true;
						break;
					}
					if(flag) break;
					k++;
				}
				j++;
			}
		}
		ans+=nn[ss].t[sss]+nn[ss].t[jj]+nn[ee].t[jj]+nn[ee].t[eee];
		cout<<ans<<endl;
		ans=0;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
