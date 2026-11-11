#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],cnt[N];
stack <int> st;
bool book[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(!book[a[i]]){
				book[a[i]]=true;
			}else{
				for(int j=1;j<=st.size();j++){
					if(st.top()==a[i]){
						st.pop();
						break;
					}else{
						st.pop(); 
						book[a[i]]=false;
					}
				}	
//				st.pop(); 
			} 
			st.push(a[i]);
		}
		for(int i=1;i<=n;i++) book[a[i]]=false;
		while(!st.empty()){
			cout<<st.top()<<" ";
			cnt[st.top()]++;
			st.pop();
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
//4 3
//1 2 1 3

//10 3
//3 1 2 1 3 2 3 1 2 1

