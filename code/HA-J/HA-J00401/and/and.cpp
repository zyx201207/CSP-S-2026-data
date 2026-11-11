#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],c[200005],c1[200005],num,num1;
int main(){
	freopen("freopen.and","r","and.in");
	freopen("freopen.and","w","and.out");
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int j=0;j<m;j++){
		int max=-1,d;
	    for(int i=0;i<n;i++){
	    	if(a[i]>=max){
	    		max=a[i];
	    		d=i;
	    	}
	    }
	    a[d]=-1;
	    b[j]=max;
    }
    while(b[0]>0){
    	int i=0;
    	c[i]=b[0]%2;
    	b[0]/=2;
    	i++;
    	num++;
    }
    for(int j=1;j<m;j++){
    	while(b[j]){
    	    int i=0;
    	    c[i]=b[j]%2;
    	    b[j]=b[j]/2;
    	    i++;
    	    num1++;
    	    if(c[i]==1&&c1[i]==1)c[i]==1;
    	    else c[i]==0;
        }
        if(num1>num)num=num1;
    }
    int s=1,num1=0;
    for(int i=num-1;i>=0;i--){
	    num1+=c[i]*s;
		s*=2;
    }
    cout<<num1;
	return 0;
}
