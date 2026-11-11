#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001],s[1001],d[1001];
int main()
{
	//
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int js=0;
		for(int j=i;j<=n;j++){
			if(js==1) break;
			s[j]=a[j];
			for(int l=n;l>=1;l--){
				if(s[l]==s[j]){
					for(int k=1;k<=l;k++){
						s[k]=-1;
					}
					js=1;break;
				}			
			}
		}
		for(int p=1;p<=n;p++) cout<<s[p]<<" ";
		cout<<endl;
		for(int p=1;p<=n;p++){
			d[s[p]]++;
		}
	}
	for(int i=1;i<=n-1;i++) cout<<d[i]<<" ";
	return 0;
}
//jue wang le ccf gei wo yi deng jiang ba
/*
4 3
1 2 1 3
*/
