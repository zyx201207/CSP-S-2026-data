#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int deep,maxi=0,ans[200005],apt=0;
bool used[200005],nn[200005];
string aaa[200005];
int f(int a,int b){
	int s=0;
	if(nn[a]&&nn[b]){
		int sum[35];
		for(int i=30;i>=0;i--){
		if(aaa[a][i]=='1'&&aaa[b][i]=='1') sum[i]=1;
		else {
			sum[i]=0;
		}
	}
	for(int i=30;i>=0;i--){
		s+=sum[i]*(int)pow(2,i);
	}
	}
	else if(nn[a]){
		int bb[35],sum[35],now=0;
	    bool flag2=false;
	    for(int i=30;i>=0;i--){
		    if(b>=(int)pow(2,i)){
			    if(!flag2){
				    flag2=true;
				    now=i;
			    }
			    bb[i]=1;
			    b-=(int)pow(2,i);
		    }
		    else bb[i]=0;
	}
	for(int i=now;i>=0;i--){
		if(bb[i]==1) aaa[b]+='1';
		else aaa[b]+='0';
	}
	for(int i=30;i>=0;i--){
		    if(aaa[a][i]=='1'&&aaa[b][i]=='1') sum[i]=1;
		    else {
			    sum[i]=0;
		    }
	    }
	    for(int i=30;i>=0;i--){
		    s+=sum[i]*(int)pow(2,i);
	    }
	nn[a]=true;
	nn[b]=true;
	}
	else {
	int aa[35],bb[35],sum[35],now=0,now1=0;
	bool flag1=false,flag2=false;
	for(int i=30;i>=0;i--){
		if(a>=(int)pow(2,i)){
			if(!flag1) {
				flag1=true;
				now=i;
			}
			aa[i]=1;
			a-=(int)pow(2,i);
		}
		else aa[i]=0;
		if(b>=(int)pow(2,i)){
			if(!flag2){
				flag2=true;
				now1=i;
			}
			bb[i]=1;
			b-=(int)pow(2,i);
		}
		else bb[i]=0;
	}
	now=min(now,now1);
	for(int i=now;i>=0;i--){
		if(aa[i]==1&&bb[i]==1) sum[i]=1;
		else {
			sum[i]=0;
		}
	}
	for(int i=now;i>=0;i--){
		s+=sum[i]*(int)pow(2,i);
	}
	for(int i=now;i>=0;i--){
		if(aa[i]==1) aaa[a]+='1';
		else aaa[a]+='0';
		if(bb[i]==1) aaa[b]+='1';
		else aaa[b]+='0';
	}
	nn[a]=true;
	nn[b]=true;
    }
    return s;
}
void dfs(int deep){
	if(deep==m+1){
		int cnt=ans[1];
		for(int i=2;i<=m;i++){
			cnt=f(ans[i],cnt);
		}
		maxi=max(maxi,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			apt++;
			used[i]=true;
			ans[apt]=a[i];
			dfs(deep+1);
			used[i]=false;
			apt--;
		}
	}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<maxi;
    return 0;
}
