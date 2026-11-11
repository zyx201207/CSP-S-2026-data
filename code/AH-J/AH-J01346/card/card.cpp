#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],ans[300005];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]&&i!=1){
			f=0;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			bool t[m+5];
			stack<int> b;
			memset(t,0,sizeof(t));
			for(int j=i;j<=n;j++){
				if(!t[a[j]]){
					b.push(a[j]);
					t[a[j]]=1;
				}
			}
			while(b.size()){
				ans[b.top()]++;
				b.pop();
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool t[m+5];
		stack<int> b;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(b.top()!=a[j]&&b.size()){
					t[b.top()]=0;
					b.pop();
				}
			}
			else {
				b.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(b.size()){
			ans[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
