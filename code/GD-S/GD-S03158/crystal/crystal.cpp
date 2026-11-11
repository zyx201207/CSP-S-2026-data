#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,cnt=0,maxx=0;
	int a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt++;
		}
	}
	cout<<cnt+1;
}
