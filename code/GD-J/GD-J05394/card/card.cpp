#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}; 
int a[500001],fi[300001],minn=INT_MAX,cnt[300001];
bool f;
vector<node> v;
bool cmp(node x,node y){
	return x.y<y.y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;		
		}
		if(fi[a[i]]!=0){
			v.push_back({fi[a[i]],i});
			minn=min(minn,fi[a[i]]);
		}
		fi[a[i]]=i;
	}
	if(!f){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
//	for(auto i:v){
//		cout<<i.x<<" "<<i.y<<endl;
//	}
	for(int i=1;i<=n;i++){
		queue<int> q;
		for(int k=i;k<=n;k++){
			q.push(k);
		}
		for(auto j:v){
			if(j.x<i){
				continue;
			}
			while(!q.empty()){
				if(q.front()>=j.x&&q.front()<j.y){
					q.pop();
				}else{
					break;
				}
			}
		}
		while(!q.empty()){
			//cout<<q.front()<<" ";
			cnt[a[q.front()]]++;
			q.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
