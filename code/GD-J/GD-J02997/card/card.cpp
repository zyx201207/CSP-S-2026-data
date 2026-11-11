#include<bits/stdc++.h>
using namespace std;
queue<int>q;
map<int,int>m;
bool tongji[300005];
int n,M,a[500005],Sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>M;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		m.clear();
		//q.clear();
		for(int j=i;j<n;j++){
			if(m[a[j]]!=0){
				for(int k=0;k<q.size()-m[a[j]];k++){
					m[q.front()]=0;
					q.pop();
				}
				q.push(a[j]);
				m[a[j]]=1;
			}else{
				q.push(a[j]);
				m[a[j]]=1;
			}
			while(q.size()){
				tongji[q.front()]=1;
				q.pop();
			}
		}
	}
	for(int i=0;i<M;i++){
		if(tongji[i]){
			Sum++;
		}
	}
	cout<<Sum;
	return 0;
}
