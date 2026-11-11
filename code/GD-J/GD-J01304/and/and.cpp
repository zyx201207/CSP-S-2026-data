#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
long long a[N];
long long ans=-1;
int n,m;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(int num,long long yu,int cnt){
	if(ans>yu) return ;
	if(num==m){
		if(ans<yu){
			ans=yu;
//			cout<<yu<<"  max  "<<endl;
		}
//		cout<<" ret  "<<endl;
		return ;
	}
	for(int i=cnt;i<n;i++){

//		cout<<"yu  "<<yu<<"  a[i]  "<<a[i]<<endl;
		dfs(num+1,yu&a[i],i+1);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
			cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m<=2000){
		for(int i=0;i<n;i++){
			dfs(1,a[i],i+1);
		}
	}
	cout<<ans;
	return 0;
}
