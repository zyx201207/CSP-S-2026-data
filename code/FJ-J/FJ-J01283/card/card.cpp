#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100001],ou[100001];
void car(long long s){
	int no[10001];
	for(int i=s;i<=n;i++){
		no[i]=a[i];
		for(int j=s;j<i;j++){
			if(no[j]==no[i]){
				for(int z=j;z<i;z++){
					no[z]=0;
				}
			}
		}
	}for(int z=s;z<=n;z++){
		ou[no[z]]++;
	}return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ou[i]=0;
	}
	for(int i=1;i<=n;i++){
		car(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ou[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
