#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,flag=0,ans=0,mid=0,w=1;;
long long a[500005]; 
bool cmp(int x,int y){
	return x>y;
}
bool cmp2(int x,int y){
	if(abs(mid-x)!=abs(mid-y)||x==y) return abs(mid-x)<abs(mid-y);
	else if(abs(mid-x)==abs(mid-y)) return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n%2==1) mid=a[n/2+1];
	else mid=a[n/2];
	while(m){
		flag=0;
		sort(a+1,a+n+1,cmp2);//paixu
		while(flag!=1){
			if(a[1+w]!=a[1]) {
				a[1+w]++; 
				flag=1;
			}
			else w++;
		}
		flag=0;
		m--;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=n;i++){
		if(a[i]==a[1]) ans++;
	}
	ans++;
	cout<<ans;
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7

