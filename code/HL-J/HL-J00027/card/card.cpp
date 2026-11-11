#include <bits/stdc++.h>
using namespace std;
int ans[300005];
int n,m;
int flag[300005];
int q[10]={0};
int answer(int k){
	stack<int> s;
	
	for (int i=1;i<=m;i++){
		flag[i]=0;
	}
	for (int i=k;i<=n;i++){
		int x;
		cin>>x;
		if (!flag[x]){
			s.push(x);
			flag[x]=1;
		}
		else{
			while(flag[x]==1){
			    if(s.top()==x)
			    flag[x]=0;
			    s.pop();
		    }
		    s.push(x);
		    flag[x]=1;
		}
	}
	for (int i=1;i<=m;i++){
		if (flag[i]==1){
			ans[i]+=1;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	for (int i=1;i<=n;i++){
		answer(i);
	}
    for (int i=1;i<=m;i++){
    	cout <<ans[i];
    }
	return 0;
} 
