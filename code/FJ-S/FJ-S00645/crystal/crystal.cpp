#include<bits/stdc++.h>
using namespace std;
int n,ma;
long long m,a[500001],s,h;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
		if(i>1&&a[i]!=a[i-1]){
			f=0;
		}
	}
	if(f){
		if(m*2/a[1]==ceil(sqrt(m*2/a[1]))*(ceil(sqrt(m*2/a[1]))-1)){
			cout<<ceil(sqrt(m*2/a[1]));
			return 0;
		}
		cout<<int(sqrt(m*2/a[1]));
		return 0;
	}
	for(int i=1,j=1;i<n;i++){
		for(;i+j-1<n;j++){
			ma=max(j,ma);
			s+=a[i+j-1]*j;
			h+=a[i+j-1];
			if(s>m){
				break;
			}
		}
		while(s<m){
			s-=h;
			h-=a[i];
			j--;
			i++;
			if(s<m){
				i--;
				break;
			}
		}
	}
	cout<<ma;
	return 0;
}
