#include<bits/stdc++.h>
using namespace std;
long long s,m,a[200005],h,l;
char b[200005];
int main(){
  freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   cin>>m;
   for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
   h=1;
   l=m;
while(h<l){
	if(b[h]==a[l]){
		if(a[h]>a[l]){
		a[h]=a[h]-a[l];
		l--;
	}
	else if(a[l]>a[h]){
		a[l]=a[l]-a[h];
		h++;
	}
	else{
		h++;
		l++;
	}
}
else{
	if(a[h]>a[l]){
		a[h]=a[h]-a[l];
		s=s+a[l];
		l--;
	}
	else if(a[l]>a[h]){
		a[l]=a[l]-a[h];
		s=s+a[h];
		h++;
	}
	else{
		s=s+a[h];
		h++;
		l--;
	}
}
}
cout<<s;
   return 0;
}
