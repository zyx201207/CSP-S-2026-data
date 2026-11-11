#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000]={},d[510000]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool f=true;
	int s=0;
	for(int i=1;i<n&&m>=0;i++){
		if(m>=(a[i]-a[i-1])*i&&(d[i-1]!=0||f)){
			m-=(a[i]-a[i-1])*i;
			s++;d[i]=1;
			if(f){
				s+=1;
				f=false;
			}
		}else{
			break;
		}
	}
	cout<<s;	
	return 0;
}
