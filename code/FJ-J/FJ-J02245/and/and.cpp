#include<bits/stdc++.h>
using namespace std;
int yc=1,n,m,j,k,b[200333]={},sc,bj[200333]={},minn,jss,js,maxx=0,zh;
bool pd=true;
string jg;
struct yg{
	int sj;
	string rj;
}a[200333];
bool cmp(yg x,yg y){
	return x.sj>y.sj;
}
void ss(int x){
	if(x>m){
		zh=0;
		yc=1;
		jg=a[b[1]].rj;
		for(int i=2;i<=m;i++){
			//cout<<jg<<' '<<a[b[i]].rj<<endl;
			js=min(a[b[i]].rj.size(),jg.size());
		     	jss=js;
				while(js){
				js--;
				if(jg[js]=='1'&&a[b[i]].rj[js]=='1'){
					jg.replace(js,1,"1");
				}
				else jg.replace(js,1,"0");
			}
			//cout<<js<<endl;
		}
		while(jss>=0){
			jss--;
			 if(jg[jss]=='1'){
				zh=zh+yc;
			}
			yc=yc*2;
		}
		maxx=max(maxx,zh);
		//cout<<maxx<<endl;
		x=1;
	}
	else{
		for(int i=sc+1;i<=n-m+x;i++){
			if(bj[i]==0){
			bj[i]++;
			b[x]=i;
			sc=i;
			ss(x+1);
			b[x]=0;
			sc=i-1;	
			bj[i]--;
			}
			
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].sj;
		k=a[i].sj;
		while(k){
			if(k%2==1){
				a[i].rj='1'+a[i].rj;
			}
			else a[i].rj='0'+a[i].rj;
			k=k/2;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		if(a[i].sj!=a[i-1].sj){
			pd=false;
			break;
		}
	}
	if(pd){
	cout<<a[1].sj;
	return 0;
}
	ss(1);
	cout<<maxx;
	return 0;
} 
