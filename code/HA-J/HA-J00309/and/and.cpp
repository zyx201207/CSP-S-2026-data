#include<bits/stdc++.h>
#define un long long
using namespace std;
un n,m,a[101010],x=0x3f,cnt;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(un i=1;i<=n;i++){
		cin>>a[i];
		bool flag=0;
		x=max(x,a[i]);
		for(un g=0;g<n;g++){
			if(a[i]==pow(2,g)) flag=1;
		}if(flag) cnt++;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		 cout<<(a[n]&a[1]);
		 return 0;
	}
	cout<<cnt;
	return 0;
}
