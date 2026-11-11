#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		sum+=a[i];
//		cout<<"a="<<a[i]<<" ";
//		cout<<"c="<<c[i]<<" ";
//		cout<<endl;
	}
	sum/=2;
	long long l=0,r=0,tot,ans=0;
	int id=n+1;
	for(int i=1;i<=n;i++){
		l+=a[i];
		while(r<l&&id>i){
			id--;
			if(r+a[id]<=l){
				r+=a[id];
				if(c[id]!=c[i])ans+=a[id];
			}else{
				tot=l-r;
//				cout<<"i="<<i<<" ";
//				cout<<"id="<<id<<" ";
//				cout<<"l="<<l<<" ";
//				cout<<"r="<<r<<" ";
//				cout<<"tot="<<tot<<" ";
//				cout<<"c[i]="<<c[i]<<" ";
//				cout<<"c[id]="<<c[id]<<" ";
//				cout<<endl;
				if(c[id]!=c[i])ans+=tot;
				r+=tot;
				a[id]-=tot;
				id++;
			}
		}
		if(l>=sum)break;
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
6
3 g
2 t
8 i
4 t
6 y
10

1
1000000000 a
0
*/
