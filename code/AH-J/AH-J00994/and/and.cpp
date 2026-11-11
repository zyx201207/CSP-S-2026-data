#include<bits/stdc++.h>
using namespace std;
long long a[200005],i,n,m;
long long d(long long w,long long y,long long mm){
	w++;
	if(w>n || mm<=0){
		if(mm>0){
			return 0;
		}else{
			return y;
		}
	}
	return max(d(w,y,mm),d(w,y&a[w],mm-1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mm=0;
	for(i=1;i<=n-m;i++){	
		mm=max(d(i,a[i],m-1),mm);
	}
	cout<<mm;
	return 0;
}
