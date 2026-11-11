#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n,m,c[200005],s[100005];
bool d[100005];
deque<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!d[c[j]]){
				q.push_front(c[j]);
				d[c[j]]=true;
			}else{
				while(d[c[j]]){
					d[q.front()]=false;
					q.pop_front();
					if(q.empty())break;
				}
				q.push_front(c[j]);
				d[c[j]]=true;
			}
		}
		while(!q.empty()){
			s[q.front()]++;
			q.pop_front();
		}
		q.clear();
		for(int j=1;j<=m;j++){
			d[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
