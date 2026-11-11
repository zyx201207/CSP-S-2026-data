#include<bits/stdc++.h>
using namespace std;
int n;
char c[200010];
long long x=0,a[200010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i]>>c[i];
}
if(n==1){
	cout<<x<<"\n";
	return 0;
}
for(int i=0;i<n/2;i++){
	int i1=n-i-1;
	while(a[i]!=0){
		if(c[i]!=c[i1]){
		    if(a[i]<a[i1]){
			    x+=a[i];
			    a[i1]-=a[i];
			    a[i]=0;
		    }else{
		    	x+=a[i1];
			    a[i]-=a[i1];
			    a[i1]=0;
			}
			i1--;
	    }
	}
}
cout<<x<<"\n";
return 0;
}
