#include <iostream>
#include <stack>
using namespace std;
int stat[300002];
int n,A[500002], m,Ans[300002];
stack<int> mn;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>A[i]; 
	
	int t=1;
	while(t<=n){
		for(int p=t; p<=n; p++){
			mn.push(A[p]);
			if(stat[A[p]]){
				mn.pop();
				while(mn.top()!=A[p]){
					stat[mn.top()]--;
					mn.pop();
				}
			}
			else stat[A[p]]++;
		}
		
		t++;
		for(int i=1; i<=m; i++){
			if(stat[i]) Ans[i]++;
			stat[i]=0;
		}
		while(!mn.empty()) mn.pop();
	}
	
	for(int x=1; x<=m; x++) cout<<Ans[x]<<' ';
	
	return 0;
}
