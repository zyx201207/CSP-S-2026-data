#include<bits/stdc++.h>
using namespace std;
int s[100000000],sum[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=i;j++){
			if(s[i]==s[j]&&i!=j){
				for(int x=j;x<i;x++){
					s[x]=s[x+i-j];
					s[x+i-j]=0;
				}
				break;
			}	
		}
		int sh=1;
		while(s[sh]>0){
			int a=s[sh];
			sum[a]++;
			sh++;
		}
	}for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout); 
}
