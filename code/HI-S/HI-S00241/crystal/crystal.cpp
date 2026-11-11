#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50010],z,s=1,num=0;
double bbb,c=1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];	
	    bbb+=a[i];
	}
	bbb/=n;
	for(int i=1;i<=n;i++){
	    if(a[i]-bbb<c&&a[i]>bbb){
	        z=a[i];
	        c=a[i]-bbb;
		}
		else{
		    if(bbb-a[i]<c&&a[i]<bbb){
	            z=a[i];
	            c=bbb-a[i];
		    }	
		}
	}
	for(int i=1;i<=n;i++){
	    a[i]-=z;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		if(a[s]==0){
			s++;
			i--;
			continue;
		}
		if(a[s]>0){
			a[s]--;
			continue;
		}
		if(a[s]<0){
			a[s]++;
			continue;
		}
	}
	for(int i=1;i<=n;i++){
	    if(a[i]==0)num++;
	}
	cout<<num;
	return 0;
}
