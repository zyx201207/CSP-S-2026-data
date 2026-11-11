#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1000000],z[1000000],a=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<n;j++){
			for(int f=0;f<a;f++){
				if(z[f]==s[j]){
					for(int p=0;p<a;f++){
						z[p]=0;
					}
					a=0;
					break;
				}
			}
			z[a]=s[j];
			a++;
		}
		
	}
	return 0;
}

