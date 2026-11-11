//GZ-S00097 安顺市第二高级中学 郭竞琦 
#include<bits/stdc++.h>
using namespace std;
const int Max=17;
int xxx,T;
int n,d,a[Max],ans,l,x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>xxx>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		l=a[2]=a[1];
		x=d/l;
		if(x==1){
			cout<<1;
			continue;
		}
		int j=2*x-1;
		if(j>n){
			cout<<0;
			continue;
		}
		cout<<n-j;
	}
	return 0;
}
