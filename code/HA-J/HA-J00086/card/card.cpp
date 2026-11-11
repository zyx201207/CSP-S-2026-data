#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+5;
using namespace std;
int a[N],b[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){//ÅÐ¶ÏµÚiÖÖ 
		int sum=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++) b[k]=0;
			for(int k=j;k<=n;k++){
				//cout<<k<<":"<<b[3]<<"\n";
				if(b[a[k]]==0) st.push(a[k]),b[a[k]]=1;
				else{
					//cout<<a[k]<<"!";
					while(true){
						//if(st.empty()) break;
						int tp=st.top();
						if(tp==a[k]) break;
						b[tp]=0,st.pop();
					}
					//cout<<":";
				}
			}
			bool flag=0;
			while(!st.empty()){
				if(st.top()==i) sum++;
				st.pop();
			} 
			//cout<<sum<<" ";
		}
		cout<<sum<<" ";
	}
	return 0;
}

