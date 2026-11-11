#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long s=0,p=0,minc=999999999,mina;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;p+=x;a[i]=x;
	}p=(p+m)/n;
	for(int i=1;i<=n;i++){
		if(p>=a[i])if(p-a[i]<minc){
			minc=p-a[i];
			mina=a[i];
		}
	}sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--){
		if(a[i]==mina)s++;
		if(a[i]<mina)
			if(m>=(mina-a[i])){
				m=m-(mina-a[i]);
				s++;
			}else break;
	}cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
