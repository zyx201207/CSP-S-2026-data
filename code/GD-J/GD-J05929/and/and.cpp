#include <bits/stdc++.h>
using namespace std;
int a[200000],c[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mex=-1;
	bool f=1;
int u =(1<<n) - 1;
for(int i=1;i<=u;i++){
	int q=0,s=0;
	for(int j=0;j<=n;j++){
	int k=1<<j;
	int z=i&k;
	if(z!=0){
		s++;
		c[q]=a[z];
		q++;
	}	
	if(s>m){
		f=0;
		break;
	}
	if(!f){
		continue;
	}
    int ano=c[0];
	for(j=1;j<m;j++){
		ano=ano&&c[i];
		} 
		cout<<ano<<endl;
		mex=max(mex,ano);
	}
}
cout<<n;
	return 0;
} 
