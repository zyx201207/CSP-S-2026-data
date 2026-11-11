#include<bits/stdc++.h>
using namespace std;
int n,m,qqq=-1,qw=-1e9,cnt=-1e9,c=-1,re=-1,s=-1e9;
struct S{
	int q;
	int w[35];
	int cc=0;
}a[200005];
int d[35];
bool cmp(S a,S b){
	return a.cc>b.cc;
}
int qww[200005];
bool f[200005];
void dfs(int ww){
	if(ww==m+1){
		int qwq=qww[1];
		for(int i=2;i<=m;i++){
			qwq=qwq&qww[i];
		}
		s=max(s,qwq);
		return; 
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			qww[ww]=a[i].q;
			dfs(ww+1);
			f[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].q;
		int r=a[i].q,op=0,pp=0,p=-1;
		while(r>0){
			int e=r%2;
			if(e==1){
				pp++;
				p=op;
			}
			op++;
			a[i].w[op]=e;
			r/=2;
		}
		if((pp>cnt&&re<=p)||p>re){
			cnt=pp;
			re=p;
			c=i;
		}
		qw=max(qw,a[i].q);
		if(qqq==-1){
			qqq=a[i].q;
		}else{
			qqq=(qqq&a[i].q);
		}
	} 
	if(m==1){
		cout<<qw;
		return 0;
	}
	if(m==n){
		cout<<c;
		return 0;
	}
	if(m==2){
		int o=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				int qp=a[i].q&a[j].q;
				o=max(o,qp);
			} 
		}
		cout<<o;
		return 0;
	}
	if(n<=2000){
		dfs(1);
		cout<<s;
		return 0;
	}
	for(int i=1;i<=30;i++){
		d[i]=a[c].w[i];
	}
	for(int i=1;i<=n;i++){
		if(i==c){
			a[c].cc=0;
			continue;
		}
		int ccc=0;
		for(int j=1;j<=30;j++){
			if(a[c].w[j]==a[i].w[j]&&a[c].w[j]==1){
				ccc++;
			}
		}
		a[i].cc=ccc;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m-1;i++){
		for(int j=1;j<=30;j++){
			d[j]=min(d[j],a[i].w[j]);
		}
	}
	int qwq=0,t=1;
	for(int i=1;i<=29;i++){
		qwq+=d[i]*t;
		t*=2;
	}
	cout<<qwq;
	return 0;
} 
