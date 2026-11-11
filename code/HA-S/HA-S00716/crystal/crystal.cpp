#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],b[1000010],m2;
int num=0,num2=-10086;
int hc(int x){
	b[x]=a[x];
	if(x<n)hc(x+1);
	m2=0;
	for(int j=1;j<=n;j++){
		num=0;
		b[j]+=1;
		if(m2!=m)m2++;
		for(int l=1;l<=n;l++){
			if(b[l]==b[l+1]){
				num++;
			}
		}
		if(num>num2){
			num2=num;
		}
		if(m2==m)return num2;
	}
	return num2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<hc(1);
	return 0;
} 
