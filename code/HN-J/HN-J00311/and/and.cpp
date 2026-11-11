#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1;
int a[100005];
bool b[100005];
int f(int x,int c,int t){
	if(c>m){
		maxx=max(maxx,x);
		return 0;
	}
	for(int i=t+1;i<n;i++)
		if(!b[i]){
			b[i]=1;
			f(x&a[i],c+1,i);
			b[i]=0;
		} 
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		b[i]=1;
		f(a[i],2,i);
		b[i]=0;
	} 	
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

