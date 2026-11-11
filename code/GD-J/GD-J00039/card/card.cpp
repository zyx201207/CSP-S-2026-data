#include<iostream>
#include<set>
#include<vector>
using namespace std;

const int MAXN=5e5+5;
const int MAXM=3e5+5;

struct Pos{
	int pos;
	bool is=0;
} p[MAXM];

int n,m,maxw=-1;
int a[MAXN];
int cnt[MAXM];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxw=max(maxw,a[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxw;j++){
			p[j].pos=0;
			p[j].is=0;
		}
		vector<int> v(n-i+1);
		int pt=0;
//		printf("第%d局游戏\n",i);
		for(int j=i;j<=n;j++){
//			printf("现在放入%d\n",a[j]); 
			if(!p[a[j]].is){
//				printf("不存在a[%d]\n",j);
				v[pt]=a[j];	
//				printf("v[%d]=a[%d]\n",pt,j);
				p[a[j]].is=1;
				p[a[j]].pos=pt;
				pt++;
//				printf("指针移到%d\n",pt);
			}else{
//				printf("之前存在a[%d],移动到p[a[%d]]=%d的下一个位置\n",j,j,p[a[j]].pos); 
				pt=p[a[j]].pos+1;
			}
		}
		for(int k=0;k<pt;k++){
//			printf("统计v[%d]=%d加一\n",k,v[k]); 
			cnt[v[k]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
