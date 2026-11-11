#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int pos[N];
int desk[N];
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){                                     
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			desk[j]=0;
			pos[j]=0;
		}
;		for(int j=i;j<=n;j++){
			if(!pos[a[j]]){
				 desk[j]=a[j];
				 pos[a[j]]=j;
			}
			else{
				for(int k=pos[a[j]]+1;k<=j;k++){
					pos[desk[k]]=0;
					desk[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			ans[desk[j]]++;
		}
		/*
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' '<<desk[i]<<"     ";
		}
		cout<<endl;
		* */
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}