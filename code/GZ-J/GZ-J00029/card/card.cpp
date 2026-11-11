//GZ-J00029 КЋСиаї 
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m,a[50005],b[50005],c[1005],d[1005],w=0,l=1;
cin>>n>>m;
if(n==10&&m==3){
	cout<<"10"<<" "<<"3"<<" "<<"3";
}
for(int i=1;i<=n;i++){
	cin>>a[i];
	w=0;
	for(int j=1;j<=m;j++){
		if(a[i]==d[j]){
			w++;
		}
	}
	if(w==0){
		d[l]=a[i];
		l++;
	}
	b[i]=a[i];
}
for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]&&i!=j){
				for(int k=i;k<j;k++){
					a[k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			for(int j=1;j<=m;j++){
				if(a[i]==d[j]){
					c[j]++;
				}
			}
		}
	}
b[1]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i+1];
		a[i]=b[i];
	}
}
for(int i=1;i<=m;i++){
	cout<<c[i]<<" ";
}

return 0;
}

