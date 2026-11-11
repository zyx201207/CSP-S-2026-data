//GZ-S00221 安顺市第一高级中学 张承潇
#include<bits/stdc++.h>
using namespace std;

const int maxm=5e5+20;
const int maxn=520;
int c,n,m,d,q,k;
int a[maxm];
int pass[maxm];
int p[maxn][maxn];
vector<int> station[maxn];
vector<int> hall[maxn];
int tmp[maxn],cnt;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
		
	int Id,Time;
	for(int i=1;i<=n;i++){
		scanf("%d",&k); 
		for(int j=1;j<=k;j++){
			scanf("%d %d",&Id,&Time);
			station[i].push_back(Id);
			pass[Id]++;
			hall[i].push_back(Time);
		}
		
	}
	
	int _srt,_end;
	for(int i=1;i<=n;i++){
		int len=station[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				_srt=station[i][j];
				_end=station[i][k];
				p[_srt][_end]=hall[i][j]+hall[i][k];
				p[_end][_srt]=p[_srt][_end];
			}
		}
	} 
	
	int srt,end,ans;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&srt,&end);
		ans=INT_MAX;
		
		if(p[srt][end])
			ans=p[srt][end];
		else
			for(int j=1;j<=m;j++)
				if(pass[j]>1)
					ans=min(ans,p[srt][j]+p[j][end]);
					
			
		ans+=a[srt]+a[end];	
		printf("%d\n",ans);
	}
	
	
	return 0;
}






