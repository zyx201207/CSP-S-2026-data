#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1;
int n,m,an[N],t[N],b=1;
int pi[N]={0},T[N]={0},k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			pi[j]=an[j+i-1];
			T[an[j+i-1]]++;
			for(int z=1;z<=m;z++){
				if(T[z]==2){
					k=z;
					break;
				}
			}
			if(k!=0){
				for(int z=1;z<=n-i+1;z++){
					if(pi[z]==k && b==0){
						break;
					}
					if(pi[z]==k && b==1){
						b=0;
					}
					if(b==0){
						T[pi[z]]--;
						pi[z]=0;
					}
				}
				b=1;
				k=0;
			}
		}
		for(int j=1;j<=n-i+1;j++){
			t[pi[j]]++;
		} 
		for(int j=1;j<=n;j++){
			pi[j]=0;
			T[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}
