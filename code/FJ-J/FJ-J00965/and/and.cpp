#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[300000];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
void get_5(){
	sort(a+1,a+1+n,cmp);
	cout<<a[m]<<endl;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n,cmp);
		cout<<a[1]<<endl;
		return 0;
	}
	if(m==2){
		sort(a+1,a+1+n,cmp);
		cout<<a[2]<<endl;
		return 0;
	}
	get_5();
	return 0;
}
