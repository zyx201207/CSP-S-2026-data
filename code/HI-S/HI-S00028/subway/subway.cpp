#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int ztw[500005];
bool bj[500005];

struct node{
	int ans;
	int zt[25];
	int ztv[25];
}a[505];

int st,en,mi;

void js(int ii,int jj,int answ){
	if(jj==en){
		mi=min(answ+ztw[en],mi);
		return;
	}
	for(int i=1;i<=a[ii].ans;i++){
		if(!bj[a[ii].zt[i]]){
			int ls=a[ii].zt[i];
			for(int j=1;j<=n;j++){
				for(int k=1;k<=a[j].ans;k++){
					if(a[j].zt[k]==ls){
						bj[ls]=true;
						js(j,ls,answ+a[ii].ztv[i]+a[j].ztv[k]);
						bj[ls]=false;
					}
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
		cin>>ztw[i];
	}
	for(int i=1,s;i<=n;i++){
		cin>>s;
		a[i].ans=s;
		for(int j=1;j<=s;j++){
			cin>>a[i].zt[j]>>a[i].ztv[j];
		} 
	}
	while(q--){
		cin>>st>>en;
		mi=INT_MAX;
		bj[st]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].ans;j++){
				if(a[i].zt[j]==st){
					js(i,st,ztw[st]+a[i].ztv[j]);
				}
			}
		}
		bj[st]=false;
		cout<<mi<<"\n";
	}
	return 0;
}

