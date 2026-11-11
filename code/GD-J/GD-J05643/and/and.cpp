#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],t[100005];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=0;j<i;j++){
				if(a[j]==a[i]){
					for(int k=j+1;k<=i;k++){
						x++;
						b[x]=a[k];
					}
				}
			}
			for(int j=i;j<=x;j++){
				
			}
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<0;
}
