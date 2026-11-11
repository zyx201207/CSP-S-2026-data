//GZ-J00069 遵义市新蒲新区滨湖中学 刘李皓阳  
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int n, m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n+1,cmp);
	long long num = a[0];
	for(int i = 1;i <= m - 1;i++) num = num&a[i];
	cout<<num;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
