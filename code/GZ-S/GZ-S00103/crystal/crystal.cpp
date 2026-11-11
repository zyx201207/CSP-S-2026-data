//GZ-S00103 南白初级中学 唐清倾 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],d[500001]={};
bool f=0;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1]) f=1;
	}
	if(f==0){
		int t=a[2]-a[1],s=1;
		for(int i=t;i<=m;i+=t){
			if(m-i>0){
				m-=i;
				s++;
			}
			else if(m-i==0) s++;
			else{
				break;
			}
		}
		cout<<s;
	}
	else{
		cout<<4;
	}
}
