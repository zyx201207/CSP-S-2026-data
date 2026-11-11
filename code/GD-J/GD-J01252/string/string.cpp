#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[200005];
char c[200005];
long long mi(long long a,long long b){
	if(a<b)return a;
	return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    long long num=0;
    while(l<r){
    	long long mii=mi(a[l],a[r]);
    	if(c[l]!=c[r])num+=mii;
		a[l]-=mii;
    	a[r]-=mii;
    	if(a[l]==0)l++;
    	if(a[r]==0)r--;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
