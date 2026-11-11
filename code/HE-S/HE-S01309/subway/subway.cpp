#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,cnt,l,r;
int w[500005],le[500005],tu[500005];
string a[500005],t[500005],v[50005];
void dfs(int step,int line,int ans){
	if(a[line][step]-'0'==r){
		ans+=w[r]+t[line][step]-'0';
		cnt=min(cnt,ans);
		return;
	}
	for(int i=step+1;i<le[line];i++){
		//cout<<line<<" "<<a[line][step]<<"->"<<line<<" "<<a[line][i]<<" "<<ans<<"->"<<ans+t[line][step]-'0'<<endl;
		dfs(i,line,ans+t[line][step]-'0');
		break;
	}
	for(int i=1;i<=n;i++){
		if(i==line) i++;
		for(int k=0;k<le[i];k++){
			if(a[i][k]==a[line][step]&&v[i][k]=='0'){
				v[i][k]='1';v[line][step]='1';
				//cout<<line<<" "<<a[line][step]<<"->"<<i<<" "<<a[i][k]<<" "<<ans<<"->"<<ans+t[line][step]-'0'<<endl;
				dfs(k,i,ans+t[line][step]-'0'); 
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;le[i]=k;
		while(k--){
			char x,y;cin>>x>>y;
			a[i]+=x;
			t[i]+=y;
			v[i]+="0";
		}
	}
	while(p--){
		cnt=1e9;
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			for(int j=0;j<le[i];j++){
				if(char(a[i][j])-'0'==l){
					dfs(j,i,w[l]);
				}
			}
		}cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
