//GZ-S00207 六盘水市第四实验中学 吴宇祥 
#include<bits/stdc++.h>
using namespace std;

int n,m,ans=1;
vector<int>a;

void su(int i=0,int j=1){
	if((a[j]-a[i])*ans<=m){
		ans++;
		m-(a[j]-a[i])*ans;
		su(i+1,j+1);
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.assign(n+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	su(0,1);
	cout<<ans<<endl;
	return 0;
}
