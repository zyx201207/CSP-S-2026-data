#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],h[200005],b[200005],ans;
stack<int>stk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (h[a[j]]==0) stk.push(a[j]);
			else{
				while(stk.top()!=a[j]) stk.pop();
				stk.pop();
				b[1]=a[j];
				ans=1;
				while(!stk.empty()){
					b[ans+=1]=stk.top();
					stk.pop();
				}
				for (int k=1;k<=ans;k++) stk.push(b[k]);
			}
		}
		bool f[200005];
		while(!stk.empty()){
			if (f[stk.top()]==0) h[stk.top()]+=1;
			f[stk.top()]=1;
			stk.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<h[i]<<' ';
	}
	return 0;
}
