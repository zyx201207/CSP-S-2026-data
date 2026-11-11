#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,bool> s;
		stack<int> sd;
		
		for(int j=i;j<=n;j++){
			if(s[a[j]]){
				while(sd.size()>0 && sd.top()!=a[j]){
					s[sd.top()]=0;
					sd.pop();
				}
			}else{
				s[a[j]]=1;
				sd.push(a[j]);		
			}
		}
		while(sd.size()>0){
			cnt[sd.top()]++;
			sd.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "; 
	}
	return 0;
} 
