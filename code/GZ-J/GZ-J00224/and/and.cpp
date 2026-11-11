//GZ-J00224 Í¿Ðù½Ü  
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mn=0;
	cin >> n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mn=max(a[i],mn);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)mn=mn&a[i];
	cout<<mn<<endl;
	return 0;
}
