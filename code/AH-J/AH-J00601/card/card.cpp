#include<bits/stdc++.h>
using namespace std;
bool t[300005];
int a[500005],res[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=0;
	a[0]=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]) flag++; 
	}
	if(flag>=n-1){
		for(int i=1;i<=n;i++){
			int k=1;
			while(a[i]==a[i+1]) k++,i++;
			res[a[i]]=res[a[i]-1]+k;
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<" ";
		return 0;
	}
	stack<int> s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!t[a[j]]) s.push(a[j]),t[a[j]]=true;
			else{
				while(1){
					int k=s.top();
					if(k!=a[j]) s.pop(),t[k]=false;
					else break;
				}
			}
		}
		while(1){
			res[s.top()]++,t[s.top()]=false;
			s.pop();
			if(s.empty()) break;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
