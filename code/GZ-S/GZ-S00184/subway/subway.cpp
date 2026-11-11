//GZ-S00184 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,n,m,d,q,w[N],k[N],a[N],t[N],cnt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
	}
	if(c==0){
		for(int r=1;r<=q;r++){
			int x,y; cin>>x>>y;
			int x1,x2,y1,y2;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(x==a[j]) x1=i,y1=j;
					if(y==a[j]) x2=i,y2=j;
				}
			}
			if(x1==x2){
				cnt=w[x]+t[y1]+w[y]+t[y2];
			}
			cout<<cnt<<endl;
		}
	}else{
		return 0;
	}
	return 0;
}
