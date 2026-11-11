#include<bits/stdc++.h>
using namespace std;
int a[500100],anstong[300100],now[500100],nowtong[300100],tong[300100],tongs[300100];
int n,m;
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	if(check()){
		for(int i=1;i<=m;i++){
			tongs[i]=tongs[i-1]+tong[i];
		}
		for(int i=1;i<=m;i++){
			cout<<tongs[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			now[j]=0;
		}
		for(int k=0;k<=n;k++){
			nowtong[k]=0;
		}
		int h=1;
		for(int tag=i;tag<=n;tag++){
			nowtong[a[tag]]++;
			if(nowtong[a[tag]]==2){
				h--;
				while(now[h]!=a[tag]){
					nowtong[now[h]]--;
					now[h]=0;
					h--;
				}
				nowtong[now[h]]--;
				now[h]=0;
			}
			now[h]=a[tag];
			h++;
		}
			for(int i=1;i<h;i++){
				anstong[now[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<anstong[i]<<" ";
		}
	}

	return 0;
} 
