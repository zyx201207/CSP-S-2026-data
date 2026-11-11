#include<bits/stdc++.h>
#define int long long
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x);
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int n,nn,m;
int a[500005];
int aa[500005];
int cnt[500005];
int b[500005],len;
int vis[300005];
int ans[300005];
int ori[500005];
int mp[500005];//[1,nn]->[1,n]
bool sub_A(){
	for(int i=2;i<=n;i++){
		if(aa[a[i]]<aa[a[i-1]]) return 0;
	}
	return 1;
}
void solve_A(){
	for(int i=1;i<=nn;i++){
		if(aa[i]!=aa[i+1]){ 
			cout<<i;
			if(i!=nn) cout<<' ';
		}
	}
	cout<<endl;
}
bool sub_13_14(){
	return m<=2;
} 
void solve_13_14(){
	if(m==1) cout<<nn<<endl;
	else{
		if(aa[1]==1){
			if(a[nn]==1){
				cout<<nn<<' '<<0<<endl;
			}else{
				int cnt=0;
				for(int i=1;i<=nn;i++){
					if(aa[i]==1) cnt++;
				}
				cout<<cnt<<' '<<nn<<endl;
			}
		}else{
			if(aa[nn]==2){
				cout<<0<<' '<<nn<<endl;
			}else{
				int cnt=0;
				for(int i=1;i<=nn;i++){
					if(aa[i]==2) cnt++;
				}
				cout<<nn<<' '<<cnt<<endl;
			}
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>nn>>m;
	for(int i=1;i<=nn;i++){
		cin>>aa[i];
	}
	int ccnt=1;
	for(int i=1;i<=nn;i++){
		if(aa[i]!=aa[i+1]||0) a[++n]=i,cnt[n]=1,ccnt=1,mp[i]=n;
		else ccnt++;
	}
	for(int i=nn;i>=1;i--){
		if(aa[i]==aa[i+1]) mp[i]=mp[i+1];
	}
	debug("n:%d\na:",n);
	for(int i=1;i<=n;i++){
		debug("%d ",a[i]);
	}
	debug("\n");
	for(int i=1;i<=n;i++){
		debug("%d ",cnt[i]);
	}
	debug("\n");
	if(sub_13_14()){
		debug("sub_13_14\n");
		solve_13_14();
		return 0;
	}
	if(sub_A()){
		debug("sub_A\n");
		solve_A();
		return 0;
	}
	for(int t=1;t<=nn;t++){
		debug("t:%d\n",t);
		while(len){
			vis[b[len]]=0;
			b[len]=0;
			ori[len]=0;
			len--;
		}
		for(int i=mp[t];i<=n;i++){
			int k=aa[a[i]];
			while(len>=vis[k]&&vis[k]) vis[b[len]]=0,b[len]=0,ori[len]=0,len--;
			len++;
			vis[k]=len;
			b[len]=k;
			ori[len]=i;
		}
		for(int j=1;j<=len;j++){
			//debug("%d ",b[j]);
			ans[b[j]]+=cnt[ori[j]];
			if(b[j]==47) debug("!!!%d\n",ans[b[j]]);
		}
		//debug("\n");
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<ans[m]<<endl;
	debug("%d",ans[47]);
	return 0;
}
