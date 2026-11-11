#include<bits/stdc++.h>
using namespace std;
int a[500050],f[500050],ans[500050],a1[500050],xa=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];	
	}
	sort(a1+1,a1+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a1[i]){
			xa=1;
		}
	}
	if(xa==1){
		for(int i=1;i<=n;i++){
			f[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			ans[i]=ans[i-1]+f[i];
		}
	}else{	
		for(int i=1;i<=n;i++){
			stack<int> sta;
			for(int j=i;j<=n;j++){
				if(f[a[j]]==1){
					int flag=0;
					while(flag==0){
						if(sta.top()==a[j]){
							flag=1;	
						}
						f[sta.top()]=0;
						sta.pop();	
					}
				}
				sta.push(a[j]);
				f[a[j]]=1;
			}
			for(int j=1;j<=m;j++){
				if(f[j]==1){
					ans[j]++;
					f[j]=0;	
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";	
	}
	return 0;
}
