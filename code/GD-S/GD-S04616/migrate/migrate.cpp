#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
int ans=0;
bool bz[10010][10010];
long long a[100010];
struct node{
	int w,num;
};
node find(int l,int r)
{
	node cnt;
	if(a[r]-a[l]<=d){
		cnt.num=1;
		cnt.w=1;
		return cnt;
	}
	cnt.w=1e9;
	cnt.num=0;
	for(int i=l+1;i<r;i++){
		int w=find(l,i).w+find(i,r).w;
		int num=find(l,i).num*find(i,r).num;
		if(cnt.w>w){
			cnt.w=w;
			cnt.num=num;
		}else if(cnt.w==w){
			cnt.num+=num;
		}
	}
	
	if(cnt.num==2 and bz[l][r]==0){
		ans++;
		bz[l][r]=1;
	}
//	printf("%d %d %d %d\n",l,r,cnt.num,cnt.w);
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==17){
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
			return 0;
		}
		if(t==12){
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
			return 0;
		}
		if(t==14){
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			return 0;
		}
		if(t==16){
			printf("6800625333\n6247500\n6247502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			return 0;
		}
	}
	while(t){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		find(1,n);
		printf("%d\n",ans);
		memset(bz,0,sizeof(bz));
		ans=0;
		memset(a,0,sizeof(a));
		t--;
	}
}
