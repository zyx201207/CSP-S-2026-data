#include <bits/stdc++.h>
using namespace std;
int n,m;
int nums[100010];
long long ma=-1;
void f(int x,int w,long long num1){
	if(w>m){
		ma=max(ma,num1);
		return;
	}
	for(int i=x+1;i<=n;i++){
		
		f(i,w+1,num1&nums[i]);
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++){
		f(i-1,1,nums[i]);
	} 
	cout<<ma;
	
	return 0;
}
