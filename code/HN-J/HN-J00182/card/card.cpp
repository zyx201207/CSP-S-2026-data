#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tm[500005];
	memset(tm,0,sizeof tm);
	stack<int>q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(tm[a[j]]!=0){
				while(q.size()!=tm[a[j]]){
					tm[q.top()]=0;
					q.pop();
				} 
			}
			else{
				q.push(a[j]);
				tm[a[j]]=q.size();
			}
		}
		while(q.size()){
			s[q.top()]++;
			tm[q.top()]=0;
			q.pop();
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}


