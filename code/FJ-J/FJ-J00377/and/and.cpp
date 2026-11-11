#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[2000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int step=1;
	ans=0;
	while(ans==0){
		ans=a[step];
		for(int i=step;i<m+step;i++){
			ans=ans&a[i];
		}
		if(ans==0){
			step+=m;
			ans=a[step];
		}
		else{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
} 
