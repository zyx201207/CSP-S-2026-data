#include<bits/stdc++.h>
using namespace std;
unsigned int n,m;
unsigned int a[200050];
unsigned int k=0,cnt=0;
bool flag=false;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(unsigned int i=1;i<=n;i++)cin>>a[i];
	for(unsigned int index=2147483648;index>0;index>>=1){
		cnt=0;
		for(unsigned int i=1;i<=n;i++)
			if(a[i]&index)cnt++;
		if(cnt>=m)k+=index,flag=true;
		if(flag){
			for(unsigned int i=1;i<=n;i++)
				if(!(a[i]&index))a[i]=0;
		}
	}
	cout<<k;
	return 0;
}
