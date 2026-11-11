#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],now[300005],pos[300005],tot,has;
int tim[500005],ans[300005];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(!f){
		for(int i=1;i<=n;i++) pos[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<pos[i]<<' ';
		//cout<<1111111111;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(now[a[j]]>0){
				tot=has-pos[a[j]]+1;
				for(int p=pos[a[j]];p<=has;p++) now[tim[p]]--;
				has-=tot;
				for(int p=1;p<=m;p++) pos[p]=0;
				for(int p=1;p<=has;p++) pos[tim[p]]=p;
				has++;
				pos[a[j]]=has;
				now[a[j]]++;
				tim[has]=a[j];
			}else{
				has++;
				tim[has]=a[j];
				now[a[j]]++;
				pos[a[j]]=has;
			}
		}
		for(int j=1;j<=m;j++){
			if(now[j]>0) ans[j]++;
		}
		has=0;
		for(int j=1;j<=m;j++) now[j]=pos[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
