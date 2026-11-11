#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,minn=2147483647;
struct oop{
	int a[20],t[20],k;
}xian[505];int tim1[100001]={};
bool xz[10001][10001];//记录线/站 
bool io[100001];
void bfs(int st,int en,int time,int dan){
	io[st]=1;

	for(int ppp=1;ppp<=n;ppp++){
		if(xz[st][ppp]){//如果这个线有当前所在站 
			if(ppp!=dan){//如果这个线不是当前所在线 
				time+=xian[ppp].t[st];//站厅到站台 
				//cout<<time<<" #";
			//	time+=xian[dan].t[st];
			//	cout<<time<<" #";
			}
			//if(ppp==dan)time+=xian[dan].t[st];
			
			for(int i=1;i<=xian[ppp].k;i++){
				if(!io[xian[ppp].a[i]]){
					io[xian[ppp].a[i]]=1;
					if(ppp==dan)
					time+=xian[ppp].t[i];
//					cout<<time<<" $";
//					cout<<endl;
					if(xian[ppp].a[i]==en){
						time+=xian[ppp].t[i];
						minn=min(time,minn);
						return ;
					}
					bfs(xian[ppp].a[i],en,time,ppp);
					io[xian[ppp].a[i]]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;

		
		for(int i=1;i<=m;i++){
			cin>>tim1[i];
		}	
		for(int ooo=1;ooo<=n;ooo++){
			cin>>xian[ooo].k;
			for(int i=1;i<=xian[ooo].k;i++){
				cin>>xian[ooo].a[i]>>xian[ooo].t[i];
				xz[xian[ooo].a[i]][i]=1;
			}
		}
	for(int uuu=0;uuu<q;uuu++){
		int st,en;
		cin>>st>>en;
//		st-=1;
//		en-=1;
		int time=tim1[st]+tim1[en];
		minn=2147483647;
		//cout<<time<<endl;
		bfs(st,en,time,0);
		cout<<minn<<endl;
	}
	return 0;
}

