#include<bits/stdc++.h>
using namespace std;
const int N=1e8-1;
long long a[N];
string c[500001],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l,s=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if (c[i]==c[i-1]){
			s++;
		}
		for (int j=1;j<=a[i];j++){
			b+=c[i];
		}
    }
    if (s==n) {
        cout<<0;return 0;	
	}
    long long ans=0,k=0,t=1;
    while (t<=(b.size()+1)/2){
    	if (b[ans]!=b[b.size()-ans-1]){
    		k++;
		} 
		t++;
    	ans++;
	}
	cout<<k;
	return 0;
}