//GZ-J00579 遵义市新浦新区滨湖中学  安李晨 
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[500010],ans[300010];
set<int> s;
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
	}
	else{
		for(int i=1;i<=n;i++){
		s.clear();
		dq.clear();
		for(int j=i;j<=n;j++){
		    if(s.find(a[j])!=s.end()){
		    	int g1=dq.size()-1;
		    	for(int t=0;t<dq.size();t++){
		    		if(a[t]==a[j]){
		    			for(int g=g1;g>=t;g--){
		    				s.erase(dq[g]);
		    				dq.pop_back();
						}
					}
				}
			}
			dq.push_back(a[j]);
			s.insert(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(s.find(j)!=s.end()){
				ans[j]++;
			}
		}
	}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' '; 
	}
	return 0;
}

