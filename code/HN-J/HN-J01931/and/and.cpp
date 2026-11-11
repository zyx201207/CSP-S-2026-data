#include<bits/stdc++.h> 
using namespace std;
int x[200005],n,m,ans=0;
//bool b[200005];
//int f(int m){
//	if(m==0||ans==0){ans++;return 0;}
//	for(int i=0;i<n;i++){
//		if(!b[i]){
//			ans&=x[i];
//			b[i]=true;
//			f(m-1);
//			b[i]=false;
//		}cout<<"dfs:"<<m<<"/"<<x[i]<<" "<<ans<<endl;
//	}
//	return 0;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>ans;
	x[0]=ans;
	for(int i=1;i<n;i++){
		cin>>x[i];
		if(m==n)ans&=x[i];
	}
	//f(m);
	cout<<x[n-1];
	return 0;
}
