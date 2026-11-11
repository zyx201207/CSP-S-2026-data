#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],m1,s=1,max_s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long j=0;j<n && n-j-1>max_s;j++){
		s=1;
		m=m1;
		for(long long k=j;k<n;k++){
			b[k]=a[k];
		}
		for(long long i=j;i<n && m-(b[i+1]-b[i])*(i-j+1)>=0;){
			if(b[i]!=b[i+1]){
				m=m-(b[i+1]-b[i])*(i-j+1);
				b[i]=b[i+1];
			}
			else{
				s++;
				i++;
			}
		}
		if(s>max_s){
			max_s=s;
		}
	}
	cout<<max_s;
	return 0;
}
