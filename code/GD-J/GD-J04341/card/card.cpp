#include<bits/stdc++.h>
using namespace std;
int ans[300005],a[500003],sum[300005],n,m;
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(sum,0,sizeof(sum));
		for(int j=i;j<=n;j++){
			if(sum[a[j]]>0){
				while(st.top()!=a[j]){
					sum[st.top()]--;
					st.pop();
				}
			}else{
				st.push(a[j]);
				sum[a[j]]++;
			}
		}
		while(!st.empty()){
			int c=st.top();
//			cout<<c<<" ";
			st.pop();
			ans[c]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
