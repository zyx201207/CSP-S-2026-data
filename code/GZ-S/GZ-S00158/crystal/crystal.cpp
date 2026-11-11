//GZ-S00158 贵阳市第三中学 李书涵 
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//5 5 1 2 4 8 9    5 8 -3 -1 2 2 7
	cin>>n>>m;
	int t;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t+=a[i];
	}
	t+=m;
	t/=n;
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(a[i]<t){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
