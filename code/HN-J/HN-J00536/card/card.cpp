#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5,M=5e5+5;
int n,m,a[M],tim[N];
bool h[N];
deque<int> q;
void run(int i){
	while(!q.empty()){
		q.pop_back();
	}
	int be=i;
	memset(h,false,sizeof(h));
	for(int k=i;k<=n;k++){
//		cout<<a[k]<<" ";
		if(h[a[k]]){
			while(!q.empty() && q.back()!=a[k]){
				h[q.back()]=false;
				q.pop_back();
			}
		}else{
			q.push_back(a[k]);
			h[a[k]]=true;
		}
//		if(!q.empty()){
//			cout<<q.back()<<" ";
//		}else{
//			cout<<"F";
//		}
	}
//	cout<<endl;
	while(!q.empty()){
		int x=q.back();
//		cout<<x<<" ";
		tim[x]++;
		q.pop_back();
	}
//	cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		run(i);
	}
	for(int i=1;i<=m;i++){
		cout<<tim[i];
		if(i!=m){
			cout<<" ";
		}
	}
//	cout<<endl;
	return 0;
}

