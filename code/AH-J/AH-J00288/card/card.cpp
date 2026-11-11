#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[200005],b[200005];
bool fl=true,fl2=true;
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1])fl=false;
		if(i!=1&&a[i-1]>a[i])fl2=false;
		b[a[i]]=1;
	}
	if(fl){
		for(int i=1;i<=m;i++){
			if(i==a[n])cout<<"1 ";
			else cout<<"0 ";
		}
	}else if(fl2){
		for(int i=1;i<=m;i++){
			if(b[i])cout<<"1 ";
			else cout<<"0 ";
		}
	}else{
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(b[a[j]]){
					while(!st.empty()&&b[a[j]]!=0){
						int h=st.top();
						b[h]--;
						st.pop();
					}
				}
				st.push(a[j]);
				b[a[j]]++;
			}
			while(!st.empty()){
				int h=st.top();
				ans[h]++;
				st.pop();
			}
			memset(b,0,sizeof(b));
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
