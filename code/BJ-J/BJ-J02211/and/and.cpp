#include<bits/stdc++.h>
using namespace std;
int shu[200005];
int use[200005];
long long a[200005][31];
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m,mx=0,newmx,newma=0,a1=0,a2=0,b1,b2;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>shu[i];
		use[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			newmx=shu[i]&shu[j];
			if(mx<newmx){
				mx=newmx;
				b1=i;
				b2=j;
				use[a1]=1;
				use[a2]=1;
				use[b1]=0;
				use[b2]=0;
				a1=b1;
				a2=b2;
			}
		}
	}
	int flag=0,p;
	for(int i=0;i<m-2;i++){
		for(int j=0;j<n;j++){
			if(use[j]==1){
				newmx=mx&shu[i];
				if(newma<newmx){
					newma=newmx;
					if(flag==0){
						use[i]=0;
						p=i;
					}else{
						use[p]=1;
						use[i]=0;
						p=i;
}
}
}
}
}
	cout<<newma;
}
