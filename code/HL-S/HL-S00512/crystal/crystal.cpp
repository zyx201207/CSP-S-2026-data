#include<bits/stdc++.h>
using namespace std;
long long n,m,x=0,num=0;
const int N=1e6+5;
long long a[N],nam[N];
bool b[N];
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	x=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=false;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(x==0)break;
		for(int j=1;j<=n;j++){
			nam[j]+=a[j]-a[j-i];
			if(b[j]==true)continue;
			if(nam[j]>m || j-i<=0){
				b[j]=true;
				x--;
			}
		}
		num++;
	}
	cout<<num;
	return 0;
}