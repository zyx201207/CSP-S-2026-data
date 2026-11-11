//GZ-S00440 ∆—Ω‹∫¿ ◊Ò“Â“ª÷–
#include <bits/stdc++.h>
using namespace std;
int q,t,n,m;
int a[5000015];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>q>>t;
	for(int i=1;i<t;i++){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m!=a[2]-a[1]+1)
		cout<<"0"<<endl;
	else
		cout<<n-m-1<<endl;}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m!=a[2]-a[1]+1)
		cout<<"0";
	else
		cout<<n-m-1;
	return 0;
}


