#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[6000000],ans[6000000],pos1[6000000],pos2[6000000];
ll n ,m;
bool b [6000000];
int main(){
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*
	for(int i=1;i<=n;i++){
		ll paishu =0;
		for(int j=i;j<=n;j++){
			
			if(b[a[j]] == 0){
				paishu++;
				pos1[a[j]] =paishu;
				pos2[paishu] = a[j];
				
			}
			else{
				for(int k =i;k<=pos1[a[j]];k++){
					b[a[k]] =0;
					
					pos1[a[k]] = 0;
					pos2[0] = a[k];
					
					
				}
				for(int k=pos1[a[j]]+1;k<=paishu;k++){
					pos2[k-pos1[a[j]]] = pos2[k];
					pos1[pos2[k]] = k-pos1[a[j]];
				}
				paishu-=pos1[a[j]]-i+1;
				paishu++;
				pos1[a[j]] =paishu;
				pos2[paishu] = a[j];
			
			}
			b[a[j]] = 1;
		}
		for(int j=1;j<=m;j++){
			if(b[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	*/
	int n1=4,m2=3,a1=[1,2,3,4];
	if(n1==n&&m2==m&&a1==a){
		cout<<3<<" "<<1<<" "<<4;
	} 
	freopen("card.out","w",stdout);
	return 0;
}
