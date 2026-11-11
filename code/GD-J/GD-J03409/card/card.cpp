#include<bits/stdc++.h>
using namespace std;
int n,m,s,cnt=0,l1[50005],l2[50005],l3[50005];
bool l4[50005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		l3[i]=s;
	}
	for(int w=0;w<n;w++){
		for(int i=0;i<n;i++){
			l1[i]=0;
			l2[i]=0;
			l4[i+1]=true;
		}
		for(int i=w;i<n;i++){
			l1[i]=l3[i];
			if(i==0) continue;
			for(int j=w;j<i;j++){
				if(l1[i]==l1[j]){
				for(int ij=j+1+w;ij<=i;ij++){
						l1[ij]=0;
					}
				}
			}		
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<n;j++){
				if(l1[j]==i&&l4[i]==true){
					l2[i]++;
					l4[i]=false;
				}
			}		
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<l2[i]<<' ';
	}
	return 0;
}
