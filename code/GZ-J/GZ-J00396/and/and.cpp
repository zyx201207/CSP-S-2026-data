//GZ-J00396 张轩哲 贵阳市第三中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans=0;
int a[N];
bool b[N];
string s[N],t;
int f(int x,int c){
	int sumn=1;
	for(int i=1;i<=c;i++){
		sumn*=x;
	}
	return sumn;
}
void dfs(int k,int cnt){
	if(k==n+1){
		if(cnt==m){
			int h=0;
			int w=0;
			for(int i=1;i<=n;i++){
				if(b[i]){
					t=s[i];
					w=i;
					break;
				}
			} 
			for(int i=w+1;i<=n;i++){
				if(b[i]){
					for(int j=31;j>-1;j--){
						if(t[32-j-1]==s[i][32-j-1]&&t[32-j-1]=='1'){
							t[32-j-1]='1';
						}else{
							t[32-j-1]='0';
						}
					}
				} 
			}
			for(int i=31;i>-1;i--){
				h+=f(2,i)*(t[31-i-1]-'0');
			}
			ans=max(ans,h);
		}
	}else{
		for(int i=0;i<=1;i++){
			dfs(k+1,cnt+i);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
		while(a[i]){
			s[i]=to_string(a[i]%2)+s[i];
			a[i]/=2;
		}
		for(int j=1;j<=32-s[i].size();j++){
			s[i]='0'+s[i]; 
		}
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	ans=INT_MIN;
	dfs(1,0); 
	cout<<ans;
		
	return 0;
}
