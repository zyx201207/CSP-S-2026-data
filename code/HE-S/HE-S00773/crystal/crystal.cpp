#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
long long p[100000005];
int main(){
	//freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
	long long n,m,s=0,sum=0,j=0,zuida,zuidawei;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		j=j+a[i];
	}
	sort(a+1,a+n+1);
	int jun=j/n;
	for(int i=1;i<=n;i++){
		p[i]=jun-a[i];
		if(p[i]<0){
			p[i]=p[i]*-1;
		}
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==jun+p[1]||a[i]==jun-p[1]){
			zuida=a[i];
			zuidawei=i;
		}
	}
	for(int i=zuidawei;i>=1;i--){
		if(sum<=m){
			sum=sum+zuida-i;
			a[i]=zuida;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==zuida){
			s++;
		}
	}
	cout<<s;
	//fclose(stdin);
//	fclose(stdout);
	return 0;
}
