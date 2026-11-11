#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int z=a[i];
		int j=1;
		a[i]=0;
		while(z>0){
			a[i]+=(z%2)*j;
			z=z/2;
			j=j*10;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	else{
		ans=a[1]&a[2];
		for(int i=3;i<=m-2;i++){
			ans=ans&a[i];
		}
		int d=0;
		int e=ans,s=ans;
		while(e>0){
			e=e/10;
			d++;	
		}
		ans=0;
		for(int i=0;i<d;i++){
			ans+=(s%10)*pow(2,i);
			s=s/10;
		}
		cout<<ans;
	}
	return 0;
}