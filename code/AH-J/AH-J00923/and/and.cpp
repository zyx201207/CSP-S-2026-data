#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxx=INT_MIN,max1,x;
long long a[N],s=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	if(maxx<a[i]){
		maxx=a[i];
	}
}s=a[1];
if(m==1){
	cout<<maxx;
	return 0;
}
else if(m==n){
	for(int i=2;i<=n;i++){
	s=s and a[i];
    }
    cout<<s;
    return 0;
}else if(m==2){
	max1=s and a[2];
	for(int i=3;i<=n;i++){
		x=s and a[i];
		max1=max(max1,x);
	}
	cout<<max1;
	return 0;
}
return 0;
}

