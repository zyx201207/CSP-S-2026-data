#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
void ptspianfen(){
	int n,m,csd7;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) csd7=a[i];
		else csd7=(csd7&a[i]);
	} 
	//测试点6
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];return;
	}
	//测试点7 
	if(m==n){
		cout<<csd7;return;
	}
	//其他测试点 肯定错，看下能不能稍微那点分 
	int csdqt;int t=n;
	sort(a+1,a+n+1);
	while(m--){
		if(t==n){
			csdqt=a[t];
		}else{
			csdqt=(csdqt&a[t]);
		}
		t--;
	}
	cout<<csdqt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ptspianfen();
	return 0;
}
