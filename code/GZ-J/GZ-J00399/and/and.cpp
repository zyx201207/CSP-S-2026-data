//GZ-J00399贵阳中天中学蒲科印 
#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int n,m;
int a[N];
int maxx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	return 0;
}
