//GZ-J00338 贵阳市第三实验中学 张普博 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[0];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
