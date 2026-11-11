#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int a[500005];
int ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool tmp=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]){
			tmp=1;
		}
	//	cout<<a[i]<<" ";
	}
	if(tmp==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			bool flag[500005]={0};
			while(!st.empty()){
				st.pop();
			}
			for(int j=i;j<=n;j++){
			//	cout<<flag[a[j]]<<" ";
				if(flag[a[j]]==0){
					ans[a[j]]++;
					flag[a[j]]=1;
					st.push(a[j]);
				}else{
					while(!st.empty()&&st.top()!=a[j]){
						flag[st.top()]=0;
						ans[st.top()]--;
					//	cout<<st.top()<<" ";
						st.pop();
					}
				}
			}
			//cout<<ans[2]<<" ";
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	
	return 0;
}
