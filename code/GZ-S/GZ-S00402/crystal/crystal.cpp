//GZ-J00402 六盘水市第二十四中学 廖国吉 
#include<bits/stdc++.h>
using namespace std;
int n,num=1,d=1,ss=1,t;
long long m;
long long a[1000000],c[100005],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int bb=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
	    if(a[i]!=i){
	    d=0;
		}
		if(a[i+1]-a[i]!=bb){
		ss=0;
		}
	}	
	if(d==1){
		for(int j=1;j<=n;j++){
	    if(m<0){
	   	cout<<t;
		return 0;	
		}
		t++;
	    m-=t;
	}
	}
	if(ss==1){
		for(int j=1;j<=n;j++){
	    if(m<0){
	   	cout<<t;
		return 0;	
		}
		t++;
		int sm;
		sm*=t;
	    m-=t;
	}
	}
	sort(a+1,a+n+1);
for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(c[i]>m){
			t=max(t,j-i);
			i++;
			j=i;
		}
		else c[i]=b[j]*(j-i+1);
	}
}
cout<<t;
	return 0;
}
