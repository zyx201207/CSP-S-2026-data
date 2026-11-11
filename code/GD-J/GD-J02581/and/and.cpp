#include<bits/stdc++.h>
using namespace std;
int z[200050],n,m,s=pow(2,30)-1;
int f(int k){
	int ans=0;
	while(k){
		ans+=k%2;
		k/=2;
	}
	return ans;
}
int cmp(int a,int b){
	if(f(a)==f(b)){
		return a>b;
	}
	return f(a)>f(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	sort(z+1,z+n+1,cmp);
	for(int i=1;i<=m;i++){
		s&=z[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
