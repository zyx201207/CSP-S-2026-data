#include<iostream>
#include<cstdio>
using namespace std;
int n,m,w,a;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.in","r",stdout);
    cin>>n;
    int a[n-1];
    char c[n-1],q[n-1],l[n-1];
	for(int i=0;i<n;i++){
    	cin>>a[i]>>c[i];
    	m+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			a++;
			q[a]+=c[i];
		}
	}
	for(int i=0;i<m;i++){
		l[i]=q[n-1-i];
		if(l[i]==q[i]){
			w++;
		}
	}
	cout<<m-w;
    return 0;
}
