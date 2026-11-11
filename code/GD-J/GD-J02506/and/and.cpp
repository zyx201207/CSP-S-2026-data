#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];
string to_t(int x){
	string t;
	while(true){
		t=to_string(x%2)+t;
		x/=2;
		if(x==0) break;
	}
	return t;
}
int to_ten(string s){
	int sum=1,tt=1;
	for(int i=0;i<s.size();i++){
		tt=1;
		for(int x=1;x<=i;x++){
			tt*=2;
		}
		sum+=tt; 
	}
	return sum-1;
}
void dfs(int x,int y,int cnt){
	if(y==m){
		ans=max(ans,cnt);
		return ;
	}
	if(x==n+1) return ;
	string s,a1=to_t(cnt);
	string a2=to_t(a[x]);
	for(int i=0;i<max(a1.size(),a2.size());i++){
		if((int)a1.size()<i){
			continue;
		}
		else if((int)a2.size()<i){
			continue;
		}else{
			s=to_string((a1[i]-'0')&& (a2[i]-'0'))+s;
		}
		
	}
	dfs(x+1,y+1,to_ten(s));
	dfs(x+1,y,cnt);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2000 && m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}
	if(n==2000 && m==2){
		int temp=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				string a1=to_t(i),a2=to_t(j),s;
				for(int i=0;i<max(a1.size(),a2.size());i++){
				if((int)a1.size()<i){
					continue;
				}
				else if((int)a2.size()<i){
					continue;
				}else{
					s=to_string((a1[i]-'0')&& (a2[i]-'0'))+s;
				}
				
			}
			temp=max(temp,to_ten(s));
				
				
			}
		}
		cout<<temp;
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	} 
	
	cout<<ans;
} 
