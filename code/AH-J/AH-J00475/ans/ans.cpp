#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10010],maxx=-1,x,y;
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int k=a[i]&a[j];
			cout<<a[i]<<"&"<<a[j]<<":"<<k<<endl;
			if(k>maxx){
			maxx=k;	
			x=i;
			y=j;
			cout<<"x:"<<x<<"y:"<<y<<"max:"<<maxx<<endl;
			}
		}	
		
	}
	cout<<maxx;
	
	

	return 0;
}
