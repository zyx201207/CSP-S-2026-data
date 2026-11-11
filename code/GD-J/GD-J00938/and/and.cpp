#include<bits/stdc++.h>
using namespace std;
long long a=0,sum=0;
long long c[999999];
long long h[1000][1000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a;
	cin>>sum;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	int p=0;
	if(sum==1){
		for(int i=1;i<=a;i++){
    	    for(int j=1;j<i;j++){
    	    	int q=c[i]&c[j];
    	    	p=max(p,q);
			}   	
	    }cout<<p;
	    return 0;
	}if(sum==a-1){
		p=c[1];
		for(int i=1;i<=a;i++){
			p=p&c[i];
		}cout<<p;
		return 0;
	}if(sum==a){
		cout<<0;
		return 0;
	}if(sum==2){
		p=c[3]&c[2]&c[1];
		for(int i=3;i<=a;i++){
			for(int j=2;j<i;j++){
				for(int k=1;k<j;k++){
					int q=c[i]&c[j]&c[k];
					p=max(p,q);
				}
			}
		}
		cout<<p;
		return 0;
	}
    p=c[a];
	sort(c+1,c+a+1);
	for(int i=a;i>=a-sum;i--){
		p=p&c[i];
	}cout<<p;
	return 0;
} 
