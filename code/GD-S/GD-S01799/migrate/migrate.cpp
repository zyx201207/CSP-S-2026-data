#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,mi,x[2000010],f[200010],num,tt,la,qwq,ans,kk,t1,tmp;
char cc;
int sum;
int read(){
	while(cc<'0'||cc>'9')cc=getchar();
	sum=0;
	while(cc>='0'&&cc<='9'){
		sum=sum*10+(cc-'0');
		cc=getchar();
	}
	return sum;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		mi=1e18;
		kk=0;
		t1=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1){
				mi=min(mi,x[i]-x[i-1]);
				if(kk!=0&&kk!=x[i]-x[i-1]){
					t1=0;
				}
				kk=x[i]-x[i-1];
			}
		}
		if(mi>d){
			cout<<0<<endl;
			continue;
		}
		if(t1==1){
			tmp=d/(x[2]-x[1]);
			cout<<max(0ll,n-(2*tmp-1)+1)<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d)break;
				num=1,tt=i,la=i;
				f[1]=i;
				while(tt<j){
					while(tt<j&&x[tt+1]-x[la]<=d)tt++;
					f[++num]=tt;
					la=tt;
				}
				qwq=0;
				for(int k=2;k<num;k++){
					if((x[f[k]-1]-x[f[k-1]])<=d&&(x[f[k+1]]-x[f[k]-1])<=d)qwq++;
				}
				for(int k=2;k<num;k++){
					if(f[k]-f[k-1]>=2){
						if((x[f[k]-2]-x[f[k-1]])<=d&&(x[f[k+1]]-x[f[k]-2])<=d)qwq++;
					}
				}
				if(qwq==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
