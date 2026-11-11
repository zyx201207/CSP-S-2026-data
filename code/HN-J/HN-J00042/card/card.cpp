#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
bool in(int &a,stack<int> q){
	while(!q.empty()){
		if(q.top()==a){
			return true;
		}
		q.pop();
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> a(n);
	for(int &i : a){
		scanf("%d",&i);
	}
	vector<int> u(m,0);
	for(int i=0;i<n;++i){
		stack<int> q;
		for(int j=i;j<n;++j){
			if(!in(a[j],q))
				q.push(a[j]);
			else{
				while(q.top()!=a[j])
					q.pop();
			}
		}
		while(!q.empty()){
			u[q.top()-1]++;
			q.pop();
		}
	}
	for(int &i : u){
		printf("%d ",i);
	}
	return 0;
}
