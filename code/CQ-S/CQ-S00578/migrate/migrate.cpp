#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FN "migrate"
int c,T,n,id,i1,i2,i3,to[2000005];
ll ans,d,x[2000005],c11[2000005],c12[2000005],c22[2000005];
int main(){
	freopen(FN".in","r",stdin);
	freopen(FN".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			c11[i]=c12[i]=c22[i]=0;
		}
		id=1;
		for(int i=1;i<=n;i++){
			while(id<=n&&x[id]-x[i]<=d)id++;
			to[i]=id-1;
//			cout<<to[i]<<' ';
		}
//		cout<<'\n';
		for(int i=n;i>0;i--){
			if(to[i]==i)continue;
			i1=to[i];
			ans+=c12[i1]+c22[i1];
//			cout<<i<<"->"<<i1<<':'<<c12[i1]<<','<<c22[i1]<<'\n';
			if(i>1&&to[i-1]>i)i2=to[i-1];
			else i2=i;
			if(i>2&&to[i-2]>i)i3=to[i-2];
			else i3=i;
			if(i1==i2){
				c11[i]=0;c12[i]=0;
				if(i1==i3){
					c22[i]=0;
				}else{
					c22[i]=c11[i1]+i1-i3;
				}
			}else{
				if(i2!=i&&i2==i1-1){
					c11[i]=c11[i1]+i1-i2;
					c12[i]=c12[i1];
					c22[i]=i2-i3;
				}else{
					c11[i]=c11[i1]+i1-i2;
					c12[i]=c12[i1]+c22[i1];
					c22[i]=i2-i3;
				}
			}
//			cout<<i<<':'<<c11[i]<<','<<c12[i]<<','<<c22[i]<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//17:28 like AC
