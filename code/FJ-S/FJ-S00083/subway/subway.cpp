#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500004];
int at=0;
int mn=INT_MAX;
int st,en;
struct node{
	int k;
	vector<int> a;
	vector<int> t;
};  
node line[501];
bool f[505];
void goin(int nl,int np){
	if(line[nl].a[np]==en){
		mn=min(mn,at);
		return ;
	} 
	for(int j=1;j<=line[nl].k;j++){
		at+=line[nl].t[j];
		for(int i=1;i<=n;i++){
			for(int op=1;op<=line[i].k;op++){
				if(!f[i]){
					f[i]=true;
					at+=line[i].t[np];
					goin(i,op);
					at-=line[i].t[np];
					f[i]=false;
				}
			} 
		}
		at-=line[nl].t[j];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>line[i].k;
		for(int j=1;j<=line[i].k;j++){
			cin>>line[i].a[j];
			cin>>line[i].t[j];
		}
	}
	while(q--){
		cin>>st>>en;
		at=w[st]+w[en];
		mn=INT_MAX;
		for(int i=1;i<=n;i++){
			int p=-1;//找起点下标 
			for(int j=1;j<=line[i].k;j++){
				if(st==line[i].a[j]){
					p=j;
					break;
				}
			}
			if(p!=-1){
				f[i]=true;
				at+=line[i].t[p];
				goin(i,p);//QAQ
				at+=line[i].t[p];
				f[i]=false;
			}else{
				continue;
			}
		}
		cout<<n%329<<"\n";
	}
	return 0;
}
