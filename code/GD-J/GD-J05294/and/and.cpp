#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,ma;
string st[10005];
void work(int k,string s,int j,int r){
	if(r>=n||k==m){
		int ans=0,p=1;
		for(int i=s.size()-1;i>=0;i--){
			ans=ans+p*int(s[i]-'0');
			p=p*2;
		}
		ma=max(ma,ans);
		return;
	}
	for(int i=j;i<=n;i++){
		string st1=st[i];
		for(int g=0;g<max(s.size(),st1.size());g++){
			if(s[g]==st1[g]&&s[g]=='1'){
				st1[g]='1';
			}
			else{
				st1[g]='0';
			}
		}
		work(k+1,st1,i+1,r+1);
	}
	work(k,s,j,r+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a){
			s=a%2;
			st[i]=char(s+'0')+st[i];
			a=a/2;
		}
	}
	work(1,st[1],1,0);
	cout<<ma; 
	return 0;
}
