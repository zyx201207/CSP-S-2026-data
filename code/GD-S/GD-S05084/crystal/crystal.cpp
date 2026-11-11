#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long  n,m,a[N],_max=-1;
bool yes;

int Find(int v1,int v2){
	long long ans=0,s=0;
	for(int i=v2;i>=1;i--){
		
		ans+=v1-a[i];
	
	if(ans==m){
		s++;
		break;
	}else if(ans>m){
		break;
	}else s++;
	
	}
	return s;
}
int main(){
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i]; 
  
}

sort(a+1,a+n+1);
for(int i=1;i<=n;i++){

	if(a[i]+1==a[i+1]||a[i]-1==a[i+1]) yes=0;
  else yes=1;
}
if(yes==0){
	cout<<m;
	return 0;
}
 
for(int i=n;i>=1;i--){
	long long y=Find(a[i],i);
	if(y>_max){
		_max=y;
	}
}
cout<<_max;
 return 0;
}
