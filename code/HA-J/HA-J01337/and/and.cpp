#include<bits/stdc++.h>
using namespace std;
bool cmp(int d,int e){
	return d>e;
}
int main(){
	/*freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);*/
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s[8];
	for(int i=7;i>=0;i--){
		s[i]=m%2;
		m/=2;
	}
	for(int i=0;i<n;i++){
		int k[8];
		int p[8];
	    for(int i=7;i>=0;i--){
		    k[i]=a[i]%2;
		    a[i]/=2;
    	}
    	for(int i=0;i<=7;i++){
    		p[i]=s[i]&k[i];
		}
		b[i]=p[0]*1+p[1]*2+p[2]*4+p[3]*8+p[4]*16+p[5]*32+p[6]*64+p[7]*128;
	}
	sort(b,b+n,cmp);
	cout<<b[0];
	return 0;
}
