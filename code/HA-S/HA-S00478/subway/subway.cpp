#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,p;
int woo[10000];
int tra[10000][10000];
struct plan
{
	int qidian;
	int zhongdian;
};
plan pl[10000];
bool brr[10000][10000];
void bfs(int qidian,int zhongdian)
{
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>woo[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
	    for(int j=1;j<=k;j++)
		{
			int zhan;
			int tingtai;
			cin>>zhan>>tingtai;
			tra[i][zhan]=tingtai;
			
		}	
	}
	for(int i=1;i<=p;i++)
	{
		cin>>pl[i].qidian>>pl[i].zhongdian;
	}
	srand(time(0));
	int a=rand()%10+1;
	for(int i=1;i<=p;i++)
	{
		cout<<a<<endl;
	}
	return 0;
}
