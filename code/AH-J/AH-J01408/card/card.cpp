#include<bits/stdc++.h>
#define int long long
using namespace std;

//TYX
/*我命由我不由CCF！是AK还是300+由我自己来决定bushi！！！！！
	*/
int a[200010],b[200010],T[100100],t[100010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,kkksc03=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
    
    while(kkksc03<n){
		
		memset(T,0,sizeof(T));
		int N=n-kkksc03;
		
		for(int i=1;i<=n;i++){
			b[i]=a[i+kkksc03];
		}
		stack<int>st;
		
		for(int i=1;i<=N;i++){
			
			if(T[b[i]]){
			//	cout<<i<<endl;
				while(st.top()!=b[i]){
					T[st.top()]--;
					st.pop();
				}
				T[b[i]]--;
				st.pop();
				
			}T[b[i]]++;
			st.push(b[i]);
		}
		
		while(!st.empty()){
			t[st.top()]++;
			st.pop();
		}
		kkksc03++;
		
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}
