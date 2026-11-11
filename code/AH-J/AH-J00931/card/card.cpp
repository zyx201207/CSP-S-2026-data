#include<bits/stdc++.h>
using namespace std;
long long n,m;
queue<long long> q;
long long a[9178134],t[9178134],k[9178134],po[9178136];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		po[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			t[a[j]]++;
			if(t[a[j]]==2){	
				while(!q.empty()){
					q.pop();
				}
				q.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(!q.empty()){
			//cout<<q.front()<<endl;
			k[q.front()]++;
			q.pop();
		}
		for(int j=1;j<=n;j++){
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(po[a[i]]>0){
			cout<<k[i]<<" ";
		}
	}
	return 0;
}
	
