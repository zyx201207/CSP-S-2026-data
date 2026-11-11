#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a32[31],vis[10005],cnt[10005];
struct Node{
	int num,cnt;
	string bit2;
}a[200005];
bool cmp(Node a,Node b){
	return a.num>b.num;
}
void dfs(int x){
//	printf("1\n");
	if(x>m){
//		printf("2 %d\n",x);
		ans=a[1].num;
		for(int i=2;i<=m;i++){
//			printf("%d ",cnt[i]);
			ans=ans&a[cnt[i]].num;
		}
//		printf("\n");
		return;
	}
	else{
//		printf("3\n");
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				cnt[x]=a[i].num;
				vis[i]=1;
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
}
unordered_map<int,int>mp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num); 
	}
//	printf("%d\n",n);
	for(int i=0,j=1;i<=30;i++,j*=2){
		a32[i]=j;
		mp[j]=i;
//		printf("%d ",a32[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n<=20){
//		printf("0\n");
		bool flagA=true,flagB=mp[n];
		for(int i=1;i<=n;i++){
			if(!mp[a[i].num+1])flagA=false;
			if(a[i].num!=i-1)flagB=false;
		}
		if(flagA){
//			printf("1\n");
//			for(int i=1;i<=n;i++){
//				printf("%d ",a[i].num);
//			}
//			printf("\n");
			printf("%d",a[m].num);
		}
		else if(flagB){
//			printf("2\n");
			if(m<=mp[n]){
				printf("%d",a[1].num);
			} 
			else{
				ans=a[1].num;
				for(int i=1,j=m-mp[n];i<=n&&j>0;i++){
					if(!mp[a[i].num+1]){
						ans=ans&a[i].num;j--;
					}
				}
				printf("%d",ans);
			}
		}
		else{
//			printf("3\n");
			dfs(1);
			printf("%d",ans);
		}
	}
	else if(n<=2000){
//		printf("1\n");
		if(m==1){
			printf("%d",a[1].num);
		}
		else if(m==n){
			ans=a[1].num;
			for(int i=2;i<=n;i++){
				ans=ans&a[i].num;
			}
			printf("%d",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i].num&a[j].num);
				}
			}
			printf("%d",ans);
		}
	}
	else{
		bool flagA=true,flagB=mp[n],flagC=true;
//		printf("%d\n",flagB);
		for(int i=1;i<=n;i++){
			if(!mp[a[i].num+1])flagA=false;
			if(a[i].num!=n-i)flagB=false;
			if(a[i].num>=4)flagC=false;
		}
//		printf("%d %d %d\n",flagA,flagB,flagC);
		if(flagA){
			printf("%d",a[m].num);
		}
		else if(flagB){
//			printf("1\n");
			if(m<=mp[n]){
				printf("%d",a32[mp[n]-m+1]);
			} 
			else{
				ans=a[1].num;
				for(int i=1,j=m-mp[n];i<=n&&j>0;i++){
					if(!mp[a[i].num+1]){
						ans=ans&a[i].num;j--;
					}
				}
				printf("%d",ans);
			}
		}
		else if(flagC){
//			printf("1\n");
			int n4[4];
			for(int i=1;i<=n;i++){
				n4[a[i].num]++;
			}
			if(n4[3]>=m)printf("3");
			else if(n4[2]+n4[3]>=m)printf("2");
			else if(n4[1]+n4[2]+n4[3]>=m)printf("1");
			else printf("0");
		}
		else{
			if(m==1){
				printf("%d",a[1].num);
			}
			else if(m==n){
				ans=a[1].num;
				for(int i=2;i<=n;i++){
					ans=ans&a[i].num;
				}
				printf("%d",ans);
			}
			else if(m==2){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						ans=max(ans,a[i].num&a[j].num);
					}
				}
				printf("%d",ans);
			}
			else{
				dfs(1);
				printf("%d",ans);
			}
		}
	}
	return 0;
}
