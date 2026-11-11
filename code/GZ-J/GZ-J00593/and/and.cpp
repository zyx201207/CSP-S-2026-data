//GZ-J00593 贵阳市第十八中学 向治隽逸  
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],s=0,d=0,dd=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>d){
			d=a[i];
			dd=i;
		}
	}
	s=d;
	a[dd]=0;
	for(int i=1;i<m;i++){
		d=0;
		dd=0;
		for(int j=1;j<=n;j++){
			if(a[j]>d){
				d=a[j];
				dd=j;
			}
		}
		s=s&d;
		a[dd]=0;
	}
	cout<<s;
	return 0;
}

