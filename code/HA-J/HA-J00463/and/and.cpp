#include<bits/stdc++.h>
using namespace std;
int m,n,k,jishu[31];
struct wode1{
	int q;
	string w;
}a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].q;
		stack<char>st;
		while(a[i].q!=0){
			if(a[i].q%2==1){
				st.push('1');
			}else{
				st.push('0');
			}
			a[i].q/=2;
		}
		while(st.size()<30){
			st.push('0');
		}
		while(!st.empty()){
			a[i].w+=st.top();
			st.pop();
		}
	}
	for(int k=30;k>0;k--){
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i].w[30-k]=='1'){
				p++;
			}
		}
		if(p>=m){
			for(int i=1;i<=n;i++){
				if(a[i].w[30-k]=='1'){
				
				}else{
					a[i].w="000000000000000000000000000000";
				}
			}
			jishu[k]=1;
		}else{
			jishu[k]=0;
		}
	}
	int ans=0;
	for(int i=30;i>=1;i--){
		if(jishu[i]==1){
			ans+=(int)pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}

