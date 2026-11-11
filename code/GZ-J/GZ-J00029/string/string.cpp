//GZ-J00029 КЋСиаї 
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,m,num=1;
char l;
cin>>n;
char a[200005];
for(int i=1;i<=n;i++){
	cin>>m>>l;
	for(int j=num;j<num+m;j++){
		a[j]=l;
	}
	num+=m;
}
int sum=0,k=1;
for(int i=num;i>=1;i--){
	if(a[i]!=a[k]){
		sum++;
	}
	k++;
}
cout<<sum-2;
return 0;
}
