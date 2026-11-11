//GZ-J00451 胡景天 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
bool bbb(long long a,long long b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,end,begin=1,run=0;
	cin>>n;
	end=n;
	
	long long a[n+1];
	char b[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++){
		if(a[begin]<=a[end]){
		    if(b[begin]!=b[end]){
		    	run=run+a[begin];
		    }
		    a[end]=a[end]-a[begin];
		    a[begin]=0;
		    begin++;
		}
		else{
			if(b[begin]!=b[end]){
			run=run+a[end];
		    }
		    a[begin]=a[begin]-a[end];
		    a[end]=0;
		    end--;
		}
		//cout<<run<<endl;
		if(begin==end){
			break;
		}
	}
	cout<<run;
	return 0;
}


