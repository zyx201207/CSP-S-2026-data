#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,a[200005],t[200005],t2[200005],ans;
queue<int> p;
int main(){
	cin>>n>>m;
	int n2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	while(n--){
		memset(t,0,sizeof(t));
		while(!p.empty()){
			p.pop();
		}
		for(int i=1+n2-n;i<=n2;i++){
			p.push(a[i]);
			t[a[i]]++;
			if(t[a[i]]==2){
				++ans;
				t[a[i]]=1;
				int f=0;
				cout<<(f==0||p.front()!=a[i]);
				while(f==0||p.front()!=a[i]){
					if(p.front()==a[i]){
						f=1;
						p.pop();
						continue;
					}
					t[p.front()]=0;
					p.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			t2[i]+=t[i];
		}
		cout<<p.size()<<endl;
	}
	cout<<endl;
	cout<<ans;
	for(int i=1;i<=m;i++){
		cout<<t2[i]<<' ';
	}
	return 0;
}
