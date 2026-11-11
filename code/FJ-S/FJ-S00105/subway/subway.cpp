#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll inf=(1ll<<62)-1+(1ll<<62); 
const int M=500010;
const int N=20000010;//最多边数
int w[M];
int ans=1;
int k;//点数 
ll dis[N];//单源最短路长
int vl[N];//直接长度
int nx[N];//下一个连接点
int la[N];//上一个点 
int h[N];//点所连最后一个点
bool bl[N];//是否走到 
int cnt; 
void add(int a,int b,int c){//加边,a-b距离c 
	cnt++;
	vl[cnt]=c;
	nx[cnt]=b;
	la[cnt]=h[a]; 
	h[a]=cnt;
} 
int rd(){//读入 
	int o=0;
	char a;
	if(!(cin>>a)) exit(0);
	while(a>='0'&&a<='9'){
		o=o*10+(a-'0');
		a=getchar();
	}
	return o;
}
void pt(ll o){
	if(o>9){
		pt(o/10);
	}
	putchar(o%10+'0');
}
void f(int x,int y){
	dis[x]=0;
	dis[0]=inf;
	bl[x]=0; 
	while(1){
		int u=0; 
		for(int i=1;i<k;i++){
//			cout<<i<<"   "<<bl[i]<<" "<<dis[i]<<"\n"; 
			if(bl[i]==0&&dis[i]<dis[u]) u=i; 
		}
//		cout<<":"<<u<<"\n"; 
		if(u==0)return;
		if(u==y) return;
		bl[u]=1; 
		for(int i=h[u];i>0;i=la[i]){
			if(dis[u]+vl[i]<dis[nx[i]]){
				dis[nx[i]]=dis[u]+vl[i];
			}
		} 
	} 
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(1){
		int c,n,m,d,q;
		//测试点编号,地铁线路数,地铁站数,最多线路经过数,计划数
		c=rd();
		n=rd();
		m=rd();
		d=rd();
		q=rd();
		for(int i=1;i<=m;i++){
			w[i]=rd();
		}//地铁口到站厅 
		k=m+1;//点数 
		for(int i=0,x;i<n;i++){
			x=rd();//站点数 
			if(x==2){
				int a1,a2,t1,t2;
				a1=rd();
				t1=rd();
				a2=rd();
				t2=rd();
				add(a1,a2,t1+t2);
				continue;
			}
			for(int j=0;j<x;j++){
				int a,t;//编号,站厅到站台 
				a=rd();
				t=rd();
				add(k,a,t);
				add(a,k,t); 
			}
			k++; 
		}
		/*
		cout<<"    "; 
		for(int i=0;i<=cnt;i++){
			cout<<i<<' '; 
		} 
		cout<<"\nnx  ";
		for(int i=0;i<=cnt;i++){
			cout<<nx[i]<<' '; 
		} 
		cout<<"\nvl  ";
		for(int i=0;i<=cnt;i++){
			cout<<vl[i]<<' '; 
		} 
		cout<<"\nla  ";
		for(int i=0;i<=cnt;i++){
			cout<<la[i]<<' '; 
		} 
		cout<<"\nh   ";
		for(int i=0;i<=cnt;i++){
			cout<<h[i]<<' '; 
		} 
		cout<<"\n";
		*/
		
		for(int i=0;i<q;i++){
			int x,y;
			x=rd();
			y=rd();
			for(int j=0;j<k;j++){
				bl[j]=0;
				dis[j]=inf; 
			} 
			f(x,y); 
			pt(dis[y]+w[x]+w[y]); 
			printf("\n");
		}
	}
	return 0;
}
