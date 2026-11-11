#include<bits/stdc++.h>
int num[300050];
int p[500050];
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
	int z[500050];
	int a=1;
		for(int j=i+1;j<=n;j++){
			z[a]=p[j];
			for(int k=1;k<=j;k++){
				if(z[k]==p[j]){
					z[500050]=0;
					
					a=1;
				}
				break;
			}
		    a++;
		}
		for(int y=1;y<=n;y++){
			num[z[y]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	return 0;
}
