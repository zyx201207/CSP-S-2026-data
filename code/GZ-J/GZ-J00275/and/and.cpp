//GZ-S00275  遵义市第一中学 钱晨逸 
#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
sort(a+1,a+n+1);
cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
}

