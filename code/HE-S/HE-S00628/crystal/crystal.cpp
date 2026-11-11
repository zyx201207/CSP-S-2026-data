#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500010];
bool z(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,z);
	for(int i=1;i<=n;i++){
		int t=0,sum=m;
		for(int j=i;j<=n;j++){
			int c=a[i]-a[j];
			sum-=c;
			if(sum>=0){
				//cout<<i<<" "<<j<<" "<<sum<<endl;
				t++;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
