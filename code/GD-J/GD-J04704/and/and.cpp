#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m;
int ans=0;
void backtrack(int times,int start,int path){
	if(m==times){
		ans=max(ans,path);
		return ;
	}
	if(times==0){
		for(int i=0;i<n-m+1;i++){
			backtrack(times+1,i+1,a[i]);
		}
	}
	for(int i=start;i<n;i++){
		int temp;
		temp=path&a[i];
		backtrack(times+1,i+1,temp);
		temp=a[i]&path;
		backtrack(times+1,i+1,temp);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		a.push_back(l);
	}
	backtrack(0,0,0);
	cout<<ans<<endl;
	return 0;
} 
