#include<bits/stdc++.h>
using namepare std;
int main(){
	int s[50005];
	int n,m,a=0,t,q=0;
	cin>>n,m;
	for(int i=1,i<=n,i++){
		for(int j=1,j++,j<=i){
			if(s[i]>=s[j]){
				for(int x=j,x<=i-j,x++){
					s[x]=s[x-1];
					s[j]=s[i];
				}
			}
		}
		
	}
	for(int z=1,z<=m,z++){
		if(s[n-a]<s[n-1-a]){
			for(int r=0,r<=a,r++){
				s[n-r]=s[n-r]+1;
				m=m-a
			}
		}
		else{
			a=a+1;
		}
	}
	t=s[n];
	for(int y=0,y<=n,y++){
		if (s[y]==t){
			q=q+1;
		}
	}	
	reture 0;
}
