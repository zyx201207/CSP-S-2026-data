#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001000],r[1001000];
int t[1001000],s=0,w[1001000];
void clw(){
	for(int i=1;i<=s;i++){
		w[t[i]]=i;
	}
	for(int i=s+1;i<=m;i++) w[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[a[j]]==0){
				t[++s]=a[j];
				w[a[j]]=s;
			}else{
				s=w[a[j]];
				clw();
			}
		}
		for(int j=1;j<=s;j++) r[t[j]]++;
		s=0;
		clw();
	}
	for(int i=1;i<=m;i++) cout<<r[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
