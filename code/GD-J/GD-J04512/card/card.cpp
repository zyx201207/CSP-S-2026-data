#include<bits/stdc++.h>
using namespace std;
int n,m,c[500000+10],b[500000+10],t[500000+10],o,s[300000+10];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
		b[i]=c[i];
	}
	for(int js=0;js<n;js++){
		for(int i=js;i<n;i++){
			for(int j=0;j<i;j++){
				if(b[j]==c[i]){
					for(int k=j;k<i;k++){
						b[k]=0;
					}
				}
			}
		}for(int i=0;i<n;i++){
			s[b[i]]++;
			b[i]=c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}

