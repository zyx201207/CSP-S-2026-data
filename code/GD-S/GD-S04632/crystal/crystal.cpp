#include<bits/stdc++.h>
using namespace std;
long long an[500005],k[500086];

struct node{
	long long n1,n2;
	int num;
}a[500005];
bool cmp1(node a,node b){
	return sqrt(a.n1*a.n1+a.n2*a.n2)<sqrt(b.n1*b.n1+b.n2*b.n2);
}
bool cmp2(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	k[0]=0;
	k[n+1]=0;
	sort(k+1,k+n+1,cmp2);
	for(int i=1;i<=n;i++){
		a[i].n1=abs(k[i+1]-k[i]);
		a[i].n2=(k[i-1]-k[i]);
		a[i].num=i;
	}
	/*a[1].n1=abs(k[1]-k[2]);
	a[1].n2=abs(k[n]-k[1]);
	a[1].num=1;*/
	sort(a+1,a+n+1,cmp1);
	int sta=a[1].num;
	cout<<k[sta]<<endl;

	for(int i=1;i<=n;i++){
		an[i]=abs(k[i]-k[sta]);
	}
	sort(an+1,an+n+1,cmp2);
	//for(int i=1;i<=n;i++){
	//	cout<<an[i]<<" "<<k[i]<<endl;
	//}
	int ans=0,su=0;
	while (su<m){
		ans++;	
		m-=an[ans];//+an[ans-1];
	}
	cout<<ans;
	return 0;
} 
