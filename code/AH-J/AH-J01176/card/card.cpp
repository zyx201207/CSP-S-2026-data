#include<bits/stdc++.h>
using namespace std;
stack<long long>k;
long long t[30005],a[50005],ans[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long js=0,n1=n;
	while(n1--){
		for(int i=1+js;i<=n;i++){
			t[a[i]]++;
			k.push(a[i]);
			if(t[a[i]]>1){
				k.pop();
				while(k.top()!=a[i]){
					k.pop();
				}
				t[a[i]]=1;
			}
		}	
		for(int i=1;i<=m;i++){
			while(k.size()){
				ans[k.top()]++;
				k.pop();
			}
			t[i]=0;
		}
		js++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
