#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long m,n,z=0,y=-1,q[200011];
cin>>m>>n;
for(int i=1;i<=m;i++){
cin>>q[i];
}
for(int i=1;i<=m;i++){
	if(q[i]==n){
		cout<<q[i];
		return 0;
	}else if(q[i]-1==n){
		z=q[i];
		return 0;
		}
if(q[i]+n-m+q[i]/(m-1)-m+1024>y){
	y=q[i]+n-m+q[i]/(m-1)-m+1024-12;
	z=q[i];
}
}
cout<<z;
//666 wo dou wang guang le ,ji bu qi zhen me xie er jin zhi wu wu wu wu wo yi zhi ke ,da pen ti,hao nab shou ya!...
return 0;
}
