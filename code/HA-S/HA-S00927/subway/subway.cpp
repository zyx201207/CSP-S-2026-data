#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500000],k[500],a[500][500000],t[500][500000],r[100000][2],ans[100000];
int res=INT_MAX;
int dfs(int now,int end,int li,int prli,int ti){
	if(now==end){
		res=min(res,ti);
		return ti;
	}if(li==-1){
		bool f=0;int t1_min=INT_MAX;
		for(int i=0;i<n&&i!=prli;i++){
			int temp1;
			for(int j=0;j<k[i];j++){
				if(a[i][j]==now){
					f=1;
					temp1=dfs(now,end,i,-1,ti);
				}
			}t1_min=min(t1_min,temp1);
		}if(f=0)return INT_MAX;
		else return t1_min;
	}else{
		int t2_min=INT_MIN;
		for(int i=0;i<k[li];i++){	
			if(a[li][i]==now)continue;
			return dfs(a[li][i],end,-1,li,ti+t[li][now]+t[li][a[li][i]]);
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	for(int C=0;C<c;C++){
		cin>>n>>m>>d>>q;
		for(int i=0;i<m;i++)cin>>w[i];
		for(int i=0;i<n;i++){
			cin>>k[i];
			for(int j=0;j<k[i];j++)cin>>a[i][j]>>t[i][j];
		}for(int i=0;i<q;i++){
			cin>>r[i][0]>>r[i][1];
			ans[i]+=w[r[i][0]]+w[r[i][1]]+dfs(r[i][0],r[i][1],-1,-1,0);
		}for(int i=0;i<q;i++)cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
