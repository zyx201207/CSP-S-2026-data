#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],ga[500005],jl[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ga[j]=0;
		}
		for(int j=1;j<=m;j++){
			jl[j]=-1;
		}
		int t=0;
		for(int j=i;j<=n;j++){
			t++;
			ga[t]=a[j];
			if(jl[a[j]]==-1){
				jl[a[j]]=t;
				continue;
			}
			else{
				t=jl[a[j]];
				ga[t]=a[j];
				jl[a[j]]=-1;
				continue;
			}
		}
		for(int j=1;j<=t;j++){
			s[ga[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
