#include<bits/stdc++.h>//ÎÄ¼þ²Ù×÷ 
using namespace std;
int a[500050];
int b[500050];
int c[200020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			b[j]=0;
		}
		int cnt=0;
		for(int j=i;j<=n;j++){
			int o=a[j];
			cnt++;
			b[cnt]=o;
			int t=cnt;
			for(int q=1;q<=cnt;q++){
				if(b[q]==o){
					for(int p=q;p<t;p++){
						b[p]=0;
					}
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
