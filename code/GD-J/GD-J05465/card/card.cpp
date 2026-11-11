#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],aid[500010];
vector<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(aid,0,sizeof(aid));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int ni=1;ni<=n;ni++){
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<s.size();j++){
				if(a[i]==s[j]){
					for(int k=s.size();k>j;k++){
						s.pop_back();
					}
					s.push_back(a[i]);
				}else{
					s.push_back(a[i]);
				}
			}
		}
		for(int j=1;j<=s.size();j++){
			aid[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<aid[a[i]]<<' ';
	}
	return 0;
} 
