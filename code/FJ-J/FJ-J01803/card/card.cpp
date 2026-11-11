#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500009];
int sum[300009]={0};
int now[500009]={-1};
int l=1,r=1;

int where_now(int n){
	for(int i=l;i<=r;i++){
		if(now[i]==n){
			return i;
		}
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		now[1]=a[i];
		l=1;r=1;
		
			//for(int i=l;i<=r;i++)cout << now[i];
			//cout << endl;
		
		for(int j=i+1;j<=n;j++){
			if(where_now(a[j])==-1){
				now[r+1]=a[j];
				r++;
			}else{
				r=where_now(a[j]);
				now[r]=a[j];
			}
			
			//for(int i=1;i<=r;i++)cout << now[i];
			//cout << endl;
			
			
		}
		for(int p=l;p<=r;p++){
				sum[now[p]]++;
			}
	}
	
	for(int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
