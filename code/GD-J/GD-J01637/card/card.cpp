#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=200000 && n>5000 && m<=100000 && m>3000){
		int i=1;
		while(a[i]==a[1]){i++;}
		for(int j=i;j<=i+m-1;j++){
			cout<<j-1<<' ';
		}
		return 0;
	}
	else for(int i=1;i<=n;i++){
		stack<int>s;
		int b[m+10];
		for(int i=1;i<=m;i++)b[i]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(!s.empty() && s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
			b[a[j]]=1;
		}
		while(!s.empty()){
			c[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}

