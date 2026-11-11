#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
map<int,int> k;
stack<int> t;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		map<int,int> s;
		for(int i=o;i<=n;i++){
			if(s[a[i]]){
				while(t.top()!=a[i])
					t.pop();
			}
			else{
				t.push(a[i]);
				s[a[i]]=1;
			}
		}
		while(!t.empty()){
			int tmp=t.top();
			k[tmp]++;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
