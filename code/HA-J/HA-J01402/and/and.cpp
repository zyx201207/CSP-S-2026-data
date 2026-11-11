#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N],sum;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
