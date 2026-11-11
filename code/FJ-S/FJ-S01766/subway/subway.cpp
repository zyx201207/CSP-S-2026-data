#include<bits/stdc++.h>
using namespace std;
struct qi{
	int head;
	int next;
	int num;
};
qi s[501][5001]={};
int c,n,m,d,q,ans,ml[500005],r,xx,y;
void go(int x,int sum,int lu){
	if(x==y){
		if(ans==0){
			ans=sum+ml[xx]+ml[y];
		}
		else{
			ans=min(ans,ml[xx]+ml[y]+sum);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(s[i][x].next>0){
			if(lu==i){
				go(s[i][x].next,sum,i);
			}
			else{
				go(s[i][x].next,sum+s[i][x].num+s[lu][x].num,i);
			}
		}
	}
	return;
}
void come(int x,int sum,int lu){
	if(x==y){
		if(ans==0){
			ans=sum+ml[xx]+ml[y];
		}
		else{
			ans=min(ans,ml[xx]+ml[y]+sum);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(s[i][x].head>0){
			if(lu==i){
				go(s[i][x].head,sum,i);
			}
			else{
				go(s[i][x].head,sum+s[i][x].num+s[lu][x].num,i);
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ml[i];
	}
	for(int i=1;i<=n;i++){
		cin>>r;
		cin>>c>>s[i][c].num;
		d=c;
		for(int j=2;j<=r;j++){
			cin>>c>>s[i][c].num;
			s[i][c].head=d;
			s[i][d].next=c;
			d=c;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xx>>y;
		ans=0;
		go(xx,0,0);
		come(xx,0,0);
		cout<<ans<<endl;
	}
	return 0;

