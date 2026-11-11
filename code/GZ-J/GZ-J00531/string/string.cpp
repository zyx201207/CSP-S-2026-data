//GZ-J00531 КывужабЇ ЩЬ№Љаљ
#include<bits/stdc++.h> 
using namespace std;
long long n,a[300000],i,s[300000],c,h,m,l,j;
string q;
char b[300000],w[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[0]>>b[0];
	s[0]=a[0];w[0]=b[0];
	for(i=1;i<n;i++){
		cin>>a[i]>>b[i];c=c+a[i];
		if(b[i]!=b[i-1]){
l++;s[l]=a[i];	
		} if(b[i]==b[i-1]){
			s[l]=a[i]+s[l];	
		}
	}
if(l==0){
	cout<<"0";
	return 0;
}
c=0;
for(i=0;i<n;i++){
	for(j=0;j<a[i];j++){
	q=q+b[i];
	}	
}
for(i=0;i<q.size();i++){
	if(q[i]!=q[q.size()-i-1]){
		c++;
	}
}
cout<<c/2;
	return 0;
}
