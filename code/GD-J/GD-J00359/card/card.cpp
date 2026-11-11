#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,d=1;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> b(m+1);
	vector<int> c(m+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int> e(m+1);
		for(int f=d;f<=n;f++){
			e[a[f]]++;
			if(e[a[f]]>1){
				for(int p=1;p<=m;p++)
				{
					e[p]=0;
				}
				e[a[f]]++;
			}	
		}
		d++;
		for(int p=1;p<=m;p++){
			if(e[p]>0){
				c[p]++;
			}
		}		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
}
