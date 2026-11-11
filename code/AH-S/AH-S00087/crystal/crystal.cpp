#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if((a[1]+1)==a[2]){
		long long j=1;
	    while(1){
		    if(m<j)break;
		    j++;
		    m-=j;
	    }
	    cout<<j;
	    return 0;
	}
	else{
		long long t=a[2]-a[1];
		long long j=t;
	    while(1){
	    	if(m<j)break;
	    	s++;
	    	m-=j;
		    j+=t;
	    }
	    cout<<s;
	    return 0;
	}
	return 0;
} 
