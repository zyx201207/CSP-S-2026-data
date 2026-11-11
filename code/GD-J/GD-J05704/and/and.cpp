#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],b[31],k=0,d=0;
string s1,s2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	cout<<a[2];
	fclose(stdin);
	fclose(stdout);
}
