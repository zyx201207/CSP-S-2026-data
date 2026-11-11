#include<bits/stdc++.h>
using namespace std;
vector<int>v(2*1e5);
vector<int>ans(2*1e5);
int a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>st;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
			    st.push(a[j]);
			    v[a[j]]=1; 
		    }else if(v[a[j]]==1){
		        while(st.empty()==false){
		        	v[st.top()]=0; 
		        	bool ok=false;
		        	if(st.top()==a[j]){
		        		bool ok=true;
					}
				    st.pop();
				    if(ok)break;
			    }
				st.push(a[j]);
				v[a[j]]=1;
		    }
		}	
      	for(int i=1;i<=m;i++){
      		if(v[i]==1){
      			ans[i]++;
			  }
		  }
      	v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

