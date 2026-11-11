#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],b[1000010],c[1000010];
int awy(int x){
	long long num=0,numb=-10086;
	if(!b[x]) b[x]=a[x];
	if(x<m) awy(x+1);
	for(int i=x;i<n;i++){
		for(int j=0;j<m;j++){
			num=b[j] and a[i];
			if(num>numb){
				numb=num;
			}
		}
	}
	return numb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<awy(0);
	return 0;
}
