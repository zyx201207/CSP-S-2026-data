#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
};
long long n,m;node a[500001];
bool cmp(node x,node y){
	return x.a<y.a;
}
/*bool ncf(node x,node y){
	return x.b<y.b;
}*/long long boss=-1e17;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].a);
	
	
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		a[i].b=a[i].a-a[1].a;
		a[i].c=a[i-1].c+(i-1)*(a[i].a-a[i-1].a);
	}

	for(long long i=2;i<=n;i++){
		
		long long l=1,r=i,w=0;
		while(l<=r){
			
			int mid=(l+r)/2;
			if(a[i].c-a[mid].c-(mid-1)*(a[i].a-a[mid].a)>m)l=mid+1;
			else if(a[i].c-a[mid].c-(mid-1)*(a[i].a-a[mid].a)==m){
				w=mid;
				break;
			}
			else r=mid-1;
		}
		if(w!=0)boss=max(i-w+1,boss);
		else boss=max(i-l+1,boss);
	}
	cout<<boss;
	return 0;
} 
