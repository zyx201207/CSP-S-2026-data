#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=2e5,MAX_M=2e5;
int n,m;
int a[MAX_N+10];
int bcnt[40];
void divide(int a){
	for(int i=0;i<=30;i++){
		if(a&(1<<i))bcnt[i]++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		divide(a[i]);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		if(bcnt[i]>=m){
			ans|=(1<<i);
			for(int j=0;j<=30;j++){
				bcnt[j]=0;
			}
			for(int j=1;j<=n;j++){
				if((a[j]&ans)==ans)divide(a[j]);
			}
//			for(int j=30;j>=0;j--){
//				cout<<bcnt[j]<<' ';
//			}
//			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
}
