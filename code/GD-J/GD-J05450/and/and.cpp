#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+10;
long long n,m,cnt,a[M],sh;
bool s[M];
void sss(int q,long long cn){
	if(q==m+1){
		cnt=max(cnt,cn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!s[i]){
			if(q==1)cn=a[i];
			s[i]=1;
			sss(q+1,cn&a[i]);
			s[i]=0;
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sss(1,0);
	cout<<cnt;
	return 0; 
} 
