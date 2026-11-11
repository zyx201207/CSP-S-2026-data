#include<bits/stdc++.h>
using namespace std;
long long int n,m,o,l,p,s;
int a[200010];
char b[200010];
void d(int x,char y){
	for(int i=o;i>=1;i--){
		x-=a[i];o++;
		if(x<=0){
			if(y==b[i]){
				s-=a[i]+x;
				a[i]=0-x;
			}
			return;
		}else{
			if(y==b[i]){
				s-=a[i];
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	o=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	p=m;
	m/=2;
	s=m;
	for(int i=1;i<=n;i++){
		l+=a[i];
		if(l>m){
			d(a[i]-l+m,b[i]);
			break;
		}else{
			d(a[i],b[i]);
			if(l==m)break;
		}
		
	}cout<<s;
	return 0;
}
