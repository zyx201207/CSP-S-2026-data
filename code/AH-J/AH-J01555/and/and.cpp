#include <iostream>
#include <algorithm>
using namespace std;
int a[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int p=1,flag=0;
		for(int j=1;j<=30;j++){
			p*=2;
			if(a[i]==p-1){
				flag=1;
				break;
			}
		}
		if(flag==0) f=1;
	}
	sort(a+1,a+1+n,cmp);
	if(f==0)cout<<a[m];
	
	return 0;
}
