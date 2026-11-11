#include<bits/stdc++.h>
using namespace std;
map <int,int>mo;
map <int,int>ba;
map <int,int>nb;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	} 
	for(int i=1;i<=n;i++){
		mo[a[i]]++;
		if(mo[a[i]]>1){
			for(int j=b[a[i]];j<=n;j++){
				mo[a[j]]=0;
			}
		}else{
			ba[a[i]]=i;
		}	
		nb[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>a[i];	
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<nb[i];
	}
}
