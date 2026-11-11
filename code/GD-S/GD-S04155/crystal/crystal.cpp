#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	long long mm;
	int s=0,c=0;
	mm=m;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(mm<0) break;
			mm=mm-a[j];
			s++;
		}
		mm=m;
		c=max(s,c);
		s=0;
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
