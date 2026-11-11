#include<bits/stdc++.h>
#define endl '\n'
#define i64 long long
#define i128 __int128
using namespace std;
int c,t,n,d,x[2000005],mcnt=0,a[2005][2];
void dfs(int dep,int xx,int uu){
	//cout<<"dfs("<<dep<<","<<xx<<","<<uu<<");"<<endl;
	if(uu!=-1&&a[xx][0]>dep){
		//cout<<uu<<"!="<<-1<<","<<a[xx][0]<<">"<<dep<<endl;
		a[xx][0]=dep;
		a[xx][1]=1;
	}else if(uu!=-1&&a[xx][0]==dep){
		//cout<<uu<<"!="<<-1<<","<<a[xx][0]<<"=="<<dep<<endl;
		++a[xx][1];
	}
	
	//cout<<uu<<"=="<<-1<<","<<a[xx][uu][0]<<"<"<<dep<<endl;
	for(int i=xx+1;i<=n;i++){
		if(x[i]-x[xx]<=d){
			dfs(dep+1,i,xx);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][0]=0x7f7f7f7f;
				a[i][1]=-1;
			}
		}
		dfs(1,1,-1);
		/*
		for(int i=1;i<=n;i++){
			cout<<a[i][1]<<' ';
		}
		
		cout<<endl;
		*/
		for(int i=1;i<=n;i++){
			if(a[i][1]==2){
				++mcnt;
			}
		}
		cout<<mcnt<<endl;
	}
	return 0;
}

