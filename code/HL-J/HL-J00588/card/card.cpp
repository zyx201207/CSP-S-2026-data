#include<bits/stdc++.h>
using namespace std;
int a[500005];
map<int,int> mp,ans;
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		ans[j]=0;
	}
	for(int i=1;i<=n;i++){
		q=deque<int>();
		for(int j=1;j<=m;j++){
			mp[j]=0;
		}
		mp[a[i]]=1;
		q.push_back(a[i]);
		for(int j=i+1;j<=n;j++){
			if(mp[a[j]]!=0){
				for(int l=1;l<=q.size()-mp[j]+1&&!q.empty();l++){
					mp[q.back()]=0;
					//cout<<"erase:"<<q.back()<<endl;
					q.pop_back();
				}
			}
			mp[a[j]]=int(q.size())+1;
			q.push_back(a[j]);
		}
		while(!q.empty()){
			ans[q.front()]++;
			//cout<<q.front()<<" ";
			q.pop_front();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
} 

