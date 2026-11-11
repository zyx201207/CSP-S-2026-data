#include<bits/stdc++.h>
using namespace std;
int a[20005];

int jia(int x,int t){
	//if(x==n)return ans;
	if(x==0)return ans;
	ans=ans&a[t];
	x++;t--;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,s,ans,Max=-1000;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n-s;i++){
		ans=a[i];
		if(jia(i,s)>Max)Max=ans;
		
	}
	cout<<Max;
	return 0;
}
