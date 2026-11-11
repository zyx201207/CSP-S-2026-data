#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n=0,fl=0,sum=0,m=0,ans=0;
    int t=5;
    string s;
    cin>>n;
    int a[n]={};
    char b[n]={};
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	sum=sum+a[i];
    	if(b[1]==b[i]){
    		fl=fl+1;
		}
	}
	if(fl==n){
		cout<<0;
		return 0;
	}
	if(sum%2==0){
		m=sum/2;
		t=1;
	}else{
	    m=sum-sum/2-1;
		t=0;   
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=a[i];i++){
			s=s+b[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(t==0){
			if(s[i]!=sum/2+1+i){
				ans=ans+1;
			}
		}else{
			if(s[i]!=sum/2+i){
				ans=ans+1;
			}
		}
	}
	cout<<ans;
	return 0;
}

