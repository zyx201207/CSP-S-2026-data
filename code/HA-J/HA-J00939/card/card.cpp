#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];

int mm[300010];

int s[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=i;j<=n;j++){
			s[++l]=a[j];
			for(int k=1;k<=l;k++){
				if(s[k]==s[l]){
					l=k;
				}
			}
		} 
		for(int j=1;j<=l;j++){
			mm[s[j]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	cout<<endl;
	return 0;
}
