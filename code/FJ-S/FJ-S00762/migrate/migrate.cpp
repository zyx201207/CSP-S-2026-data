#include<bits/stdc++.h>
using namespace std;

int c,t,n,minn[2000005],qzh[2000005],lt,rt,b[2000005];
long long a[2000005],d,ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				if(a[i]-a[j]<=d){
					b[i]=j;
					break;
				}
		for(int i=1;i<=n;i++){
			lt=rt=i;
			minn[i]=0;
			qzh[i]=1;
			qzh[i-1]=0;
			for(int j=i+1;j<=n;j++){
				if(b[j]==j)
					break;
				while(a[j]-a[lt]>d)
					lt++;
				while(minn[rt+1]<=minn[lt] && rt+1<j)
					rt++;
				minn[j]=minn[lt]+1;
				int x=min(3,qzh[rt]-qzh[lt-1]);
				if(x==2)
					ans++;
				qzh[j]=qzh[j-1]+x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
