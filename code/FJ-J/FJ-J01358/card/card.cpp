#include <bits/stdc++.h>
using  namespace  std;
int  s[400000],n,m,x[600000];
void  T(int  y){
	int  f[n+1],f2=0;
	for(int  i=1;i<=n;i++){
		f[i]=-1;
	}
	for(int  i=y;i<=n;i++){
		int  xx=0;
		for(int  j=1;j<=f2;j++){
			if(x[i]==f[j]){
				for(int  k=j;k<=f2;k++){
					f[k]=-1;
				}
				xx=1;
				f[j]=x[i];
				f2=j;
				break;
			}
		}
		if(xx==0){
			f2+=1;
			f[f2]=x[i];		
		}
	}
	for(int  i=1;i<=f2;i++){
		s[f[i]]++;
	}
}
int  main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int  i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int  i=1;i<=m;i++){
		s[i]=0;
	}
	for(int  i=1;i<=n;i++){
		T(i);
	}
	for(int  i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return  0;
} 
