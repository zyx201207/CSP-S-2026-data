#include<bits/stdc++.h>
using namespace std;
const int N=10010001;
int a[N],s[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int f=1;f<=n;f++){
		cnt=f;
		for(int i=f;i<=n;i++){
			for(int j=i+1;j<=n;j++)	
				if(a[i]==a[j]){
					cnt=j;
					break;
				}
			for(int j=cnt;j<=n;j++){
				s[a[f]]++;
			}
		}	
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<' ';
	return 0;
}
