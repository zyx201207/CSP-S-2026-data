#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,n,m,d,q,sum;
vector<int> beg;
vector<int> en;
bool flag[505][500005];
int a[500005],b[505][500005],r[100005][2];//每个地铁站的地铁口走到站厅需要的时间。b表示第i条地铁站台到j站站厅所需的时间，r表示旅行计划 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int e,l;
			scanf("%d%d",&e,&l);
			b[i][e]=l;
			flag[i][e]=1;
		}
	}
	for(int qwer=1;qwer<=q;qwer++){
		bool f=0;
		beg.clear();
		en.clear(); 
		sum=0; 
		int s=0,s1=0;
		int x,y;
		scanf("%d%d",&x,&y);
		sum+=a[x]+a[y];
		for(int i=1;i<=n;i++){
			if(flag[i][x]){
				beg.push_back(i);
				s++;
			}
			if(flag[i][y]){
				en.push_back(i);
				s1++;
			} 
		}
		for(int i=1;i<=min(s,s1);i++){
			if(beg[i]==en[i]){
				f=1;
				break;
			}
		}
		if(f){
			cout<<sum<<endl;
		}
	}
	return 0;
}

