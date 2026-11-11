#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int t1=1;
	stack<int>st;
	while(t1<=n){
		int t[300010]={0};
		for(int i=t1;i<=n;i++){
			if(t[a[i]]==0){
				t[a[i]]=1;
				st.push(a[i]);
				continue;
			}
			while(!st.empty()){
				int x=st.top();
				st.pop();
				t[x]=0;
				if(x==a[i])break;
			}
			st.push(a[i]);
			t[a[i]]=1;
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			c[x]++;
		}
		t1++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
