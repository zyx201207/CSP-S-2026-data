#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s[200005];
int Max=0;
string ad(string x,string y){
	string t;
	for(int i=0;i<x.size();i++){
		if(x[i]==y[i]) t=t+x[i];
	}
	return t;
}
void DFS(int n,int m,string sum,int i,vector<int> b){
	if(i==m){
		int summ=0,cnt=1;
		for(int k=0;k<sum.size();k++){
			summ+=(sum[k]-'0')*cnt;
			cnt*=2;
		}
		Max=max(Max,summ);
		return;
	}
	for(int k=1;k<=n;k++){
		bool flag=true;
		for(int p=0;p<b.size();p++){
			if(k==b[p]){
				flag=false;
				break;
			}
		}
		if(flag==true) {
			b.push_back(k);
			DFS(n,m,ad(sum,s[k]),i+1,b);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]>0){
			char c=a[i]%2+'0';
			s[i]=s[i]+c;
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++) {
		vector<int> b;
		b.push_back(i);
		DFS(n,m,s[i],1,b);
	}
	cout<<Max;
	return 0;
} 
