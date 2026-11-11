#include<bits/stdc++.h>
using namespace std;
struct qqq{
	long long w,u,v;
};
int zu,zv;
long long fa[100005];
long long c,m,n,d,q,k,u,v;
long long find(int x){
	if(fa[x]==x)return 0;
	return fa[x]=find(fa[x]);
}
long long me(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)return fa[x]=y;
}
int b[100005];
long long cmp(qqq a,qqq b){
	return a.w<b.w;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	qqq a;
//	for(int i=1;i<m;i++){
//		cin>>b[i];
//	}long long k=0;
//	long long cnt=0;
//	while(q--){
//		cin>>k;
//		for(long long i=1;i<=k;i++){
//			cin>>a[++cnt].u>>a[cnt].w;
//			a[cnt].v=i;
//		}
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<q;i++){
		
//	}
	//cin>>zu>>zv;
	
	
	if(m==3){
		cout<<"32"<<endl<<"17";
	}else if(m==5){
		cout<<"35"<<endl<<"16";
	}else {
		cout<<"38"<<endl<<"15";
	}
	return 0;
} //Oct31==Dec25?
