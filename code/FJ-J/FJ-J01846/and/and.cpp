#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans1,ans2,ans3,ans4;
void and_ans(int i,int ans,int t,int x){
	if(t>0){
		for(;i<=n-m+x;i++){
			ans=ans&a[i];
			and_ans(i+1,ans,t-1,x+1);
		}	
	}
	else{
		ans4=max(ans4,ans);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans1=max(ans1,a[i]);
	}
	if(m==1)cout<<ans1;
	else if(m==n){
		ans2=a[1];
		for(int i=2;i<=n;i++){
			ans2&=a[i];
		}
		cout<<ans2;
	}
	else if(m==2){
		for(int i=1;i<=n-m+1;i++){
			for(int j=i+1;j<=n;j++){
				ans3=max(ans3,a[i]&a[j]);
			}
		}
		cout<<ans3;
	}
	else{
		for(int i=1;i<=n-m+1;i++){
			and_ans(i+1,a[i],m-1,2);
		}
		cout<<ans4;
	}
	return 0;
}
