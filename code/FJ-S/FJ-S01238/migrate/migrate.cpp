#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e3+5;
int c,t;
long long n,d;
long long arr[N];
vector<int> brr[N];
long long minx=0x3f3f3f3f,minid;
void dfs(int x,int t,int z){
	if(x==t&&minx>z){
		minx=z;
		minid=1;
		return;
	}else if(x==t&&minx==z){
		minid++;
		return;
	}
	for(int i=0;i<brr[x].size();i++){
		dfs(brr[x][i],t,z+1);
	}
//	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
		if(c==11||c==12){
			if(arr[2]-arr[1]>d){
				printf("0\n");
			}
			continue;
		}
		memset(brr,0,sizeof(brr));
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(arr[i]-arr[j]<=d){
					brr[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				minx=0x3f3f3f3f3f;
				minid=0;
				dfs(l,r,0);
				if(minid==2){
					ans++;
//					cout<<l<<" "<<r<<endl;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
