#include<bits/stdc++.h>
using namespace std;
const long MAX=5e5+10;
int a[MAX];
int main(){
	frenpen("crystal.in","r",stdin);
	frenpen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int e=n*m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int o=0,i1=1;
	while(e){
		if(m<=0){
			cout<<o;
			return 0;
		}else{
			if(a[i1]<a[i1+1]){
				int r=a[i1+1]-a[i1];
				a[i1]+=r;
				m-=r;
				o++;
			}else if(a[i1]>a[i1+1]){
				int r=a[i1]-a[i1+1];
				a[i1+1]+=r;
				m-=r;
				o++;
			}
		}
		i1++;
	}
	return 0;
}

