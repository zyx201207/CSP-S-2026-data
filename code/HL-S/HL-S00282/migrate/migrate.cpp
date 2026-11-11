#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int C,T,n,d,a[N],r[N],sum1[N],sum2[N],sum3[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1,k=1;i<=n;i++){
			while(k<n&&a[k+1]-a[i]<=d) k++;
			r[i]=k;
//			cout<<r[i]<<" ";
//			if(r[i]==i) cout<<"!"<<i<<" ";
//			if(r[i]==i+1) cout<<"#"<<i<<" ";
		}
//		cout<<endl;
//		cout<<endl;
		for(int i=n;i>0;i--){
//			if(a[i+1]-a[i]>d) cout<<i<<" "<<a[i]<<" "<<a[i+1]<<endl;
			if(r[i]==i){sum1[i]=0;sum2[i]=0;continue;}
			int x=r[i]-2,y=r[i]-1,z=r[i];
			int xx=r[x],yy=r[y],zz=r[z];
			if(x<i) xx=z;
			if(y<i) yy=z;
			sum1[i]=sum2[i]=0;
			if(xx==zz) i=i;
			else if(yy==zz) sum2[i]=sum1[z];
			else if(yy==zz-1&&yy!=z){
				sum1[i]=sum1[z],sum2[i]=sum2[z]-sum3[z];
				if(r[yy]==r[zz]) sum2[i]=0;
			}else sum2[i]=sum2[z],sum1[i]=sum1[z];
			sum1[i]+=zz-yy;sum2[i]+=yy-xx;sum3[i]=yy-xx;
//			cout<<i<<" "<<x<<" "<<y<<" "<<z<<" "<<xx<<" "<<yy<<" "<<zz<<endl;
//			cout<<i<<" "<<sum1[i]<<" "<<sum2[i]<<endl;
			ans+=sum2[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
wo shi ju ruo,dan shi wo xiang qu WC qwq.
//freopen ni gai bu hui yi wei wo zhen de wang le freopen ba

zhu yi dao mei ge wen jian zhu shi de kai tou ji hang shi kao shi qian xie de.

15:23 kan kan C
16:26 wo gai bu hui tui chu le C ba
17:01 yang li you de mei guo you de guo le,kai shi tiao ba.
17:57 zhong yu tiao chu lai le,wo shi ju ruo

you yu ju ruo bu zhi dao neng bu neng shu ru zhong wen,er qie ying yu la wan le,suo yi ni kan dao de ji ben dou shi pin yin.
*/
