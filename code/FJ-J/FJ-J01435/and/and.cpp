#include<bits/stdc++.h>
using namespace std;
size_t n,m;
vector<size_t>p;
size_t dfs(size_t i,size_t t){
	size_t ans=0;
	for(size_t j=i;j+t-1<p.size();j++){
		if(t==1){
			if(p[j]>ans){
				ans=p[j];
			}
		}else{
			size_t temp=p[j]&dfs(j+1,t-1);
			if(temp>=ans){
				ans=temp;
			}
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p=vector<size_t>(n);
	for(size_t i=0;i<n;i++){
		cin>>p[i];
	}
	cout<<dfs(0,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
