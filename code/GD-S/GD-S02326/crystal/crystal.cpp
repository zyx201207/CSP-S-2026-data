#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s,c;
}a[500010]={};
bool cmp1(node x,node y){
	return x.s<y.s;
}
bool cmp2(node x,node y){
	return x.c<y.c;
}
long long n,m,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		sum+=a[i].s;
	}
	sum/=n;
	//cout<<sum<<endl;
	sort(a+1,a+n+1,cmp1);
	int k=1e9;
	for(int i=1;i<=n;i++){
		a[i].c=abs(a[i].s-sum);
		if(a[i].c<k)k=a[i].s;
	}
	sort(a+1,a+n+1,cmp2);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].c==0)cnt++;
		else if(m>=a[i].c){
			m-=a[i].c;
			cnt++;
		}
		//cout<<a[i].s<<" "<<a[i].c<<endl;
	}
	cout<<cnt;
	return 0;
}
