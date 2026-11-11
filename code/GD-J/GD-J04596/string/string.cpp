#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    long long a[200005],summ=0;
    char c[200005];
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long st=a[1],en=a[n];
	while(l<r){
		int minn=min(st,en);
		if(c[l]!=c[r]){
			summ+=minn;
		}
		st-=minn;
		en-=minn;
		if(en==0){
			en=a[--r];
		}
		if(st==0){
			st=a[++l];
		}
		
	}
	cout<<summ;
	return 0;
}
