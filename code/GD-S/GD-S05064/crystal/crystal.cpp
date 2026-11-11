#include<bits/stdc++.h>
using namespace std;
long long p[100005],m;
int n,i,Max=-1;
int f(){
//	cout<<i<<"f()";
	int j,c=1;
	for(j=0;j<n;j++){
		if(j!=i){
			int a=p[i]-p[j];
			if(a<0) a*=-1;
//			cout<<"/"<<a<<" "<<m<<endl;
			if(m>=a) m-=a,c++,p[i]+=a;
		} 
	}
//	cout<<"/"<<c<<" "<<i<<endl;
	return c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	for(i=0;i<n;i++){
		Max=max(Max,f());
	}
	cout<<Max;
	return 0;
}
