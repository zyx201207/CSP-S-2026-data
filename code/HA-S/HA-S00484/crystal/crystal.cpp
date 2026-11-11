#include<bits/stdc++.h>
using namespace std;
struct sj{
	int a,goal;
}dis[500005];
int cmp(sj x,sj y){
	return x.a<y.a;
}
int n,m,ans=0,b[10005][10005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>dis[i].a;
	sort(dis+1,dis+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=dis[j].a-dis[i].a;
		}
	}
	for(int i=1;i<=n;i++){
		int s1=INT_MAX;
		for(int j=1;j<=n;j++){
			if(b[j][i]<s1&&b[j][i]>=0&&i!=j){
				s1=b[j][i];
				c[i]=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int s1=0,s=1,cnt1=1,cnt2=1;
		s1+=b[c[i]][i];
		while(((b[c[i]-cnt1][i]>=0&&c[i]-cnt1!=i)||(b[c[i]+cnt2][i]>=0&&c[i]+cnt2!=i))&&c[i]-cnt1>=0){
			if((b[c[i]+cnt2][i]<0&&c[i]-cnt1!=i)||(c[i]+cnt2==i&&b[c[i]-cnt1][i]>=0)||(b[c[i]-cnt1][i]<=b[c[i]+cnt2][i]&&b[c[i]-cnt1][i]>=0&&i>c[i]-cnt1)){
				s1+=b[c[i]-cnt1][i];
				cnt1++;
				if(s1>m)
					break;
				s++;
			}
			else if((b[c[i]-cnt1][i]<0&&c[i]+cnt2!=i)||(c[i]-cnt1==i&&b[c[i]+cnt2][i]>=0)||(b[c[i]-cnt1][i]>=b[c[i]+cnt2][i]&&b[c[i]+cnt2][i]>=0&&i>c[i]+cnt2)){
				s1+=b[c[i]+cnt2][i];
				cnt2++;
				if(s1>m)
					break;
				s++;
			}
			
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}

