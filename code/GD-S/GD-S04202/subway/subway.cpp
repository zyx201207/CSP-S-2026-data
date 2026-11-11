#include<bits/stdc++.h> 
using namespace std;

int c,n,m,d,q;
int w[500086];
int k[1086];
struct subway_line{
	int num;
	int len; 
}line[500086];
int ans[1086][1086];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	
	memset(ans,0x3f,sizeof(ans));
	
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>line[j].num>>line[j].len;
		}
		for(int st=1;st<=k[i];++st){
			for(int en=st+1;en<=k[i];++en){
				ans[line[st].num][line[en].num]=min(ans[line[st].num][line[en].num],line[st].len+line[en].len);
				ans[line[en].num][line[st].num]=min(ans[line[en].num][line[st].num],line[st].len+line[en].len);
			}
		}//确认同一条线中，各站之间的距离 
	}
	
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]); 
			}
		} 
	}//Floyd预处理：计算从 i 到 j 经 k 点换乘所需的时间 
	
	int s,t;
	for(int i=1;i<=q;++i){
		cin>>s>>t;
		cout<<ans[s][t]+w[s]+w[t]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
