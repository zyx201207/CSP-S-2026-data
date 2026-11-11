#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
long long n,m,ans=0,num=0;
long long a[maxn];

int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[ans]+=a[i];
	}
	
	long long g=ans/n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==g)num++;
	}
		for(int i=1;i<=n;i++){
			if(m>0){	
				if(a[i]==g){
					num++;
					continue;
				}else{
					m-=abs(a[i]-g);
					num++;
				}
			}else{
				cout<<num;
				break;
			}
		}
	return 0;
}
