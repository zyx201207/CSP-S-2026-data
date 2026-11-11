#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,aa[1001],nn=0,sum=0;
    string t,b;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>aa[i]>>t;
    	for(int o=0;o<aa[i];o++){
    		b+=t;
    		nn++;
		}
	}
	for(int i=0;i<(nn+1)/2;i++){
		if(b[i]!=b[n-i-1])sum++;
	}
	cout<<sum<<endl;
	return 0;	
} 
