//GZ-J00468 遵义市第十二中学 周泽恩 
#include<bits/stdc++.h>

using namespace std;
int n,m;
int ans;
int a[1000005];
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
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	int vl=2;
	for(int i=1;i<m;i++){
		ans=(ans&a[vl++]);
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
