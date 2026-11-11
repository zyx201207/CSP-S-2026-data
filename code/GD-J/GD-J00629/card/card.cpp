#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500000],cnt[300000];
string s;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i]+'0'; 
	}
	
	for(int i=0;i<n;i++){
		bool vis[300000]={};
		string ss=s;
		
		ss.erase(0,i);
		
		int idx[300000];
		for(int j=0;j<n-i;j++){
			if(!vis[ss[j]-'0']){
				vis[ss[j]-'0']=true;
				idx[ss[j]-'0']=j;
			}else{
				ss.erase(idx[ss[j]-'0'],j-idx[ss[j]-'0']);
				
				idx[ss[j]-'0']=j;
			}
		}
		
		int len=ss.size();
		for(int j=0;j<len;j++){
			cnt[ss[j]-'0']++;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
