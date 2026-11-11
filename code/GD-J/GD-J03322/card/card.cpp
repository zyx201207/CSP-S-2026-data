#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int const N=5e5+10;
int arr[N];
int a[N];
int num[N];
stack<int> stk1,stk2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			a[j]=arr[j+i-1];
		}

		for(int j=1;j<=n-i+1;j++){
			
			
			if(stk1.empty()) stk1.push(a[j]);
			else{
				int x=a[j];
				bool f=0;
				while(!stk1.empty()){
					if(stk1.top()==x){
						stk1.pop();
						f=1;
						break;
					}
					stk2.push(stk1.top());
					stk1.pop();
					
				}
				if(f){
					while(!stk2.empty()){
						stk2.pop();
					}
				}
				if(!f){
					while(!stk2.empty()){
						stk1.push(stk2.top());
						stk2.pop();
					}
					
				}
				stk1.push(x);
			}
			if(j==n-i+1){
				while(!stk1.empty()){
					num[stk1.top()]++;
					stk1.pop();
				}
				while(!stk2.empty()){
					stk2.pop();
				}
			}
			
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	
	return 0;
} 
