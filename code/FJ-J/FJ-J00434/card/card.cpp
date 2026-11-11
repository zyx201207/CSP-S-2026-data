#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005];
long long ton[300005],sum[300005];
stack<long long> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
	
		for(int i=t;i<=n;i++){
		
			ton[a[i]]++;
			if(ton[a[i]]>1){
			
				while(st.top()!=a[i]&& !st.empty()){ 
					ton[st.top()]--;
					st.pop();
					
				}
				ton[a[i]]=0;
			}else{
			
				st.push(a[i]);
			}	
		}
	
		for(int k=1;k<=m;k++){
			ton[k]=0;
		}
		while(!st.empty()){
			sum[st.top()]++;
			st.pop();
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
