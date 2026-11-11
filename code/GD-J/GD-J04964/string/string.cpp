#include<bits/stdc++.h>
using namespace std;
int x=0,n,a[10008],b,c[20005],k[20005],h=1,t;
long long m=0;
char p;
int one(int t,int h){
	if(t<=h){
	    return 0;
    }
    if(k[h]==k[t]){
    	if(c[h]>c[t]){
		    c[h]-=c[t];
		    return one(--t,h);
		}
		else if(c[h]<c[t]){
		    c[t]-=c[h];
		    return one(t,++h);
		}
		else{
			return one(--t,++h);
		}
	}
	else {
		if(c[h]>c[t]){
			m+=c[t];
		    c[h]-=c[t];
		    return one(--t,h);
		}
		else if(c[h]<c[t]){
			m+=c[h];
		    c[t]-=c[h];
		    return one(t,++h);
		}
		else{
			m+=c[h];
			return one(--t,++h);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>p;
		k[i]=p-'a';
	}
	t=n;
	one(t,h);
	cout<<m;
	return 0;
} 
