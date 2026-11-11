#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)ans=ans&a[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//ys uid:230118859
	return 0;
}
