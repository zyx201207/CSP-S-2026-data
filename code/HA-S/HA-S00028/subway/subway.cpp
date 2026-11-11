#include <bits/stdc++.h> 
using namespace std;
int cc,n,m,d,p;
int a[500005],b[500005],pl[500005][3],nn[500005],ca[5005][5005], c[201][500005][3],q[500005][5];

//int check(int i,int j,int k,int l)
//{
//	//c[j][k][0]=
//	//time+=c[fin1][fin2][1];
//	//c[j][k][0]=
//	return 0;
//}
//struct lian()
//{
//	int st,ed;
//}li[500005];
int main()
{
	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>p;
	
	//出入站耗时 
	for (int i = 1;i<=m;i++)
	{
		cin>>a[i];
	}
	//地铁线路+各站点耗时 
	for (int i = 1;i<=2;i++)
	{
		cin>>nn[i];
		for (int j = 1;j<=nn[i];j++)
	{
		cin>>c[i][j][0]>>c[i][j][1];
	}
	}
	for (int i = 1;i<=p;i++)
	{
		cin>>pl[i][0]>>pl[i][1];
	}
	
	for (int i = 1;i<=p;i++)
	{
		int time = 0;
//		pl[i][0];pl[i][1];
		time+=a[pl[i][0]]+a[pl[i][1]];
		
		//遍历地铁站 ,找始终站点 
		int fin1 = 0,fin2 = 0,fid1 = 0,fid2 = 0;
		for (int j = 1;j<=n;j++) 
		{
			for (int k = 1;k<=nn[j];k++) 
		{
			//cout<<c[j][k][1]<<"  ";
			if (c[j][k][0]==pl[i][0])
				time+=c[j][k][1];
				fin1 = j;
				fin2 = k;
				
			if (c[j][k][0]==pl[i][1])
				time+=c[j][k][1];
				fid1 = j;
				fid2 = k;
		}
		}
		if (fin1==fid1){
			cout<<time<<endl;
			break;}
		for (int k = 1;k<=nn[fin1];k++) 
		{
			//c[j][k][0]=
			//
			for (int j = 1;j<=nn[fid1];j++){
			
				if (c[fin1][k][0]==c[fid1][j][0])
				q[c[fin1][k][0]][0] = fin1;
				q[c[fin1][k][0]][1] = k;
				q[c[fin1][k][0]][2] = fid1;
				q[c[fin1][k][0]][3] = j;
				}
				//check(fin1,fin2,fid1,fid2);
		}
		cout<<q[j][0];
		//d[c[fin1][k][0]][0]
		for (int j =1;j<=10;j++){
		if (q[j][0] == fin1 && q[j][2] == fid1){
		time+=c[fin1][q[j][1]][1]+c[fid1][q[j][3]][1];
		cout<<time<<' ';
		return 0;
		}}
	}
	return 0;
}
