#include<bits/stdc++.h> 
using namespace std;
int a[1000000+10];
int b[1000000+15];
int c[1000000+16];
bool d[1000000+17];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>> n>>m ;
	long long x=n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long sum=0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[j]=a[j];
			long long u=0;
			for(int k=i;k < j;k++){
				if(b[k]==b[j]){
					u=1;
					b[k]=0;
				}
				if(u==1)b[k]=0;
			}
			for(int k=i;k <= n;k++){
				if(b[k]!=0&&d[b[k]]==false)
				{
					c[b[k]]++;
					d[b[k]]=true;
				}
			}	
		}
		for(int k = i;k <= n;k++){
			d[b[k]]=false;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << c[i]<<" ";
	}
	return 0;
}
