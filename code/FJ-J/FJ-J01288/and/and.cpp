#include<bits/stdc++.h>
using namespace std;
int d=0,d2=0;
void han(int x2,int y2){
int a[1000],b[1000],c[1000];
	int k=0,k2=0;int o;long long two=1;
    while(x2){
		a[k]=x2%2;//cout<<a[k]<<" ";
		x2=(x2-x2%2)/2;
		k++;
	}
		while(y2){
		b[k2]=y2%2;
		y2=(y2-y2%2)/2;
		k2++;
	}
	o=max(k,k2);
	for(int e=0;e<o;e++){
		if(a[e]==b[e]&&a[e]==1)c[e]=1;
		else c[e]=0;
	}
	for(int i=0;i<o;i++){
		d+=c[i]*two;
		two*=2;
	//	cout<<d<<" ";
	}
 // cout<<d;

}
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans[1000000][100000],an;
	cin>>n>>m;
	for(int z=1;z<=n;z++){
		for(int z2=1;z2<=z;z2++){
			
			if(m-1>=0){
		    han(ans[z][m],ans[z-1][m]);
			ans[z][m]=d;
			ans[z][m]=max(ans[z-1][m],ans[z][m--]);
			}
			
   an=ans[z][z2];
		 
	}
}
 cout<<an;
	return 0;
}
