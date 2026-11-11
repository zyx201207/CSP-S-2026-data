#include <bits/stdc++.h>
using namespace std;
int num[100000],l=0;
void two(int x,int now){
	if(x==0) return;

	l=now;
	two(x/2,now+1);
	num[now]=x%2;
}
int num2[100000],l2=0;
void two2(int x,int now){
	if(x==0) return;

	l2=now;
	two2(x/2,now+1);
	num2[now]=x%2;
}
int ten(){
	int ans=0;
	for(int i=l;i>=0;i--){
		ans+=pow(2,i)*num[i];
	}
	return ans/2;
}

void ad(int x,int y){
for(int i=0;i<=max(l,l2);i++){
	num[i]=0;
	num2[i]=0;
}
two(x,1);
two2(y,1);
for(int i=0;i<=max(l,l2);i++){
	num[i]=(num[i]==1&&num2[i]==1)?1:0;
}
return;}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m,a[100000],ma=0;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(i>=1){
		ad(a[i],a[i-1]);
		ma=max(ma,ten());
	}
}
cout<<ma;
return 0;}



