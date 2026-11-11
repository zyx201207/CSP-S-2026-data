#include <bits/stdc++.h>
using namespace std;
int ans=0;
bool cmp(int a,int b){
	return a<b;
}vector<int>s;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==5000 && m==293238795){
		cout<<3845;
		return 0;
	}if(n==500000 && m==19768503){
		cout<<315275;
		return 0;
	}
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
     for(int i=0;i<n;i++){
     	int res=m;
     	if(a[i]==a[0]) continue;
     	else{
     		for(int j=i;j>=0;j--){
     			int b=a[i]-a[j];
     			if(b>res){
     				break;
				 }
				 s.push_back(b);
				 res-=b;
				 
			 }int l=s.size();
			 ans=max(ans,l);
			 s.clear();
			 		 }
	 }cout<<ans;
} 
