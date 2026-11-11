#include<bits/stdc++.h>
using namespace std;
char a[500005],c[500005];
bool b[500005],e[500005];
int minn=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n;
	int d[m]={};
	int k=n,s=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<minn){
			minn=a[i];
		}
	}
	int g=minn;
	while(n!=0){
	for(int i=s;i<k;i++){
		c[i]=a[i];
		if(b[a[i]-'0']==false){
			b[a[i]-'0']=true;
		}else{
			int j=i-1;
			while(a[j]!=a[i]){
				e[j]=false;
				j--;
			}
			e[j]=false;
		}
	}
	int cnp=minn;
	for(int j=s;j<k;j++){
		if(e[j]){
			d[cnp]++;
			cnp++;
		}else{
			e[j]=true;
		}
	}
	n--;
	s++;
	}
	for(int i=g;i<=t;i++){
		d[i]=d[i+m];
		if(d[i]!=0){
			cout<<d[i]<<" ";
		}
	}
	return 0; 
}
