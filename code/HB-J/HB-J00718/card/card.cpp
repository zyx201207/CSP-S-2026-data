#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[300001]={0};
void cd(int b){
	int c[500001]={0};
	for(int i=b;i<=n;i++){
		 s[a[i]]++;
		 c[i]=a[i];
	}
	for(int i=b;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[i]==c[j]&&c[i]!=0){
				for(int k=i;k<j;k++){
					s[c[k]]--;
					c[k]=0;
				}
			}			
		}
	}
}
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++) cd(i);
   for(int i=1;i<=m;i++) cout<<s[i]<<" ";
   return 0;
}
