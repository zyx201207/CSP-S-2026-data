#include<bits/stdc++.h>
using namespace std;
int n,m,js,Answer=0,a[200010],f=1;
void DFS(int x,int st,int Count){
	if(x>m){
		Answer=max(Answer,Count);
		return;
	}
	for(int i=st;i<=n;i++){
		DFS(x+1,i+1,(Count&a[i]));
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	int b=a[i]+1;
    	while(!(b&1)){
    		b/=2;
		}
		if(b!=1){
			f=0;
		}
	}
	sort(a+1,a+1+n);
	js=a[2];
	if(f){
		cout<<a[n-m+1];
	}
	for(int i=3;i<=n;i++){
		js&=a[i];
	}
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		cout<<(js&a[1]);
	}
	else if(m==n-1){
		cout<<js;
	}
	else{
		DFS(1,1,pow(2,30)-1);
		cout<<Answer;
	}
}
