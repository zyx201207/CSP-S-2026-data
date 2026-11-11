#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m,num=1,ans=0,lans=0,cn=1;
int a[N],ton[N];
void f(int x){
	for(int i=x+1;i<=n-m+1;i++){
		if(num!=m) {
			num++; ton[++cn]=a[i]; f(i);
		}
		if(num==m){
			for(int j=m;j>1;j--){
				for(int h=1;h<j;j++){
					lans+=ton[j]&ton[h];
				}
			}
			ans=max(ans,lans);
			num--;lans=0;ton[cn]=0;cn--;
			return;
		}
 
	}
	num--;ton[cn]=0;cn--;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int Max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(m==1){
		cout<<Max;
		return 0;
	}
	ton[1]=a[1];
	f(1);
	cout<<ans;
	return 0;
}
/*
4 3
3 15 12 12
*/

