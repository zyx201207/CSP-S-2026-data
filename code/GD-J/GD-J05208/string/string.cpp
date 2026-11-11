#include<bits/stdc++.h>
using namespace std;
long long n,x,a[200005],t1,t2,cnt=0;
char c[200005];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		while(x--) s1+=c;
 	}
	for(int i=0;i<s1.size()/2;i++){
	    if(s1[i]!=s1[s1.size()-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
/*
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
 	}
	t1=a[1];
	t2=a[n];
	int k1=1,k2=n;
	while(k1<=k2){
		if(a[k1]>a[k2]){
			if(c[k1]!=c[k2]) cnt+=a[k1]-a[k2];
			a[k1]-=a[k2];
			if(c[k1]!=c[k2]) k2--;
		}else if(a[k2]>a[k1]){
			if(c[k1]!=c[k2]) cnt+=a[k2]-a[k1];
			a[k2]-=a[k1];
			if(c[k1]!=c[k2]) k1++;
		}else{
			//cnt+=a[k1];
			k1++;
			k2--;
		}
	}
	cout<<cnt;
	return 0;
}*/
