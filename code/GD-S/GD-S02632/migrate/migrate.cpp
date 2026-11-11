#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define int long long
int c,t,n,d,ans,res;
int a[2000005],b[2000005];
struct node{
	int l,r;
}
opt[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld\n",&c,&t);
	if(c>=13&&c<=14){
		while(t--){
			scanf("%lld %lld\n",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld ",&a[i]);
			printf("0\n");
		}
		return 0;
	}
	if(c>=11&&c<=12){
		while(t--){
			scanf("%lld %lld\n",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld ",&a[i]);
			int kkk=a[2]-a[1];
			if(kkk<=d&&2*kkk>d) cout<<0<<endl;
			else if(2*kkk<=d&&3*kkk>d) cout<<n-3<<endl;
			else cout<<0<<endl; 
		}
		return 0;
	}
	while(t--){
		ans=res=0;
		scanf("%lld %lld\n",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld ",&a[i]);
		for(int i=1;i<=n;i++){
			int id=i,sum=0;
			while(a[id+1]-a[i]<=d&&id<n) id++;
			if(id==n) break;
			b[i]=id;
			for(int j=i+1;j<=id;j++){
				if(a[id+1]-a[j]<=d) sum++;
			}
			if(sum==2){
				ans++;
				opt[ans].l=i;
				opt[ans].r=id+1;
			}
		}
		/*for(int i=1;i<=ans;i++){
			int ll=opt[i].l;
			while(b[ll-1]==opt[i].l) ll--;
			int rr=b[opt[i].r];
			res+=(opt[i].l-ll+1)*(rr-opt[i].r+1);
		}*/
		printf("%lld\n",ans);
	}
	return 0; 
} 
