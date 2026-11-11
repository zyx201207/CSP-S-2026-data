#include<bits/stdc++.h>
using namespace std;
int m,n;
string a[200005];
bool cmp(string x,string y){
	if(x.length()>y.length())return 1;
	else if(x.length()==y.length()&&x>=y)return 1;
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
