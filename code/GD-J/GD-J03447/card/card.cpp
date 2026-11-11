#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int n,m,a;
int b[1000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		
		b[a]+=1;
		if(b[a]>1){
				while(st.top()==a){
					b[st.top()]=0;
					st.pop();
				}
				
					st.pop();
					b[a]-=1;
			
		
	}
	st.push(a);

}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
