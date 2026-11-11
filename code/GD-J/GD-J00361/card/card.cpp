#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
int n,m,cnt[500005],a[500005],f[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		a[i]=i;
    }
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(!f[a[j]]){
				s.push(a[j]);
				f[a[j]]=true;
			}else{
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}
		}while(!s.empty()){
			cnt[s.top()]++;
			f[s.top()]=0;
			s.pop();
		}
	}for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
