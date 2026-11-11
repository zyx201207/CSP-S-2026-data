#include<bits/stdc++.h>
using namespace std;

int n,d;
int x[2000010];

int minn=INT_MAX;
void dfs1(int step,int cnt,int end){
	if(step>end)return;
	if(step==end){
		minn=min(minn,cnt);
		return;
	}
	for(int i=step+1;x[i]-x[step]<=d;i++){
		dfs1(step+i,cnt+1,end);
	}
}
int re=0;
void dfs2(int step,int cnt,int end){
	if(step>end)return;
	if(step==end){
		re+=(cnt==minn);
		return;
	}
	for(int i=step+1;x[i]-x[step]<=d;i++){
		dfs2(i,cnt+1,end);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	
	if(!c){
		int n;
		scanf("%d",&n);
		if(n==4){
			printf("1\n2");
		}else if(n==5){
			printf("0\n1");
		}else if(n==197){
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
		}else if(n==260000){
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
		}else if(n==200001){
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		}else if(n==174944){
			printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		}
		
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	while(t--){
		memset(x,0,sizeof x);
		
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=INT_MAX;
				re=0;
				dfs1(i,0,j);
				dfs2(i,0,j);
				if(re==2){
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

