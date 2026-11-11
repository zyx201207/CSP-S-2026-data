#include <bits/stdc++.h>
using namespace std;
long long maxnum=-1,bothnum;
int n,m;
const int h=1e5+5;
long long a[h];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+n,a+1+n,cmp);
for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
		bothnum=a[i]&a[j];
		if(bothnum>maxnum){
			maxnum=bothnum;
		}
	}
}
if(m==n){
	maxnum=a[1];
	for(int i=1;i<=n;i++){
		maxnum=maxnum&a[i];
	}
}
cout<<maxnum;
fclose(stdin);
fclose(stdout);
	return 0;
}
