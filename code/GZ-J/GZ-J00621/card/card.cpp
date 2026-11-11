#include<bits/stdc++.h>
using namespace std;
int s[10005];int t[1000];int n,m,a[10005];
int pd(int x,int y){
	for(int i=1;i<=n;i++){
		if(s[i]==x){
			return i;
		}
	}
	return 0;
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j>i-1){
				if (pd(a[j],j)){
					for(int l=pd(a[j],j);l<=n;l++){
						s[l]=0;
					}
				}
				s[i]=a[j];
			} 
		}
		for(int i=1;i<=n;i++){
			t[s[i]]+=1;
		}
	}
	for(int i=1;i<=1005;i++){
		if(t[i]!=0)cout<<t[i];
	}
	//fclose(stdin,stdout);
	return 0;
}
