#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5,M = 3e5+5;
int t[M];
int a[N];
int n,m;
bool book[M];
int cd[N],tot;
bool flag_A = true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag_A = false;
	}
	if(flag_A){
		for(int i = 1;i<=n;i++){
			memset(book,0,sizeof(book));
			memset(cd,0,sizeof(cd));
			tot = 0;
			for(int j = i;j<=n;j++){
				int c = a[j];
				if(!book[c]){
					cd[++tot] = c;
					book[c] = true;
				} 
			}
			for(int j = 1;j<=tot;j++){
				t[cd[j]]++;
			}
		}
	}else{
		for(int i = 1;i<=n;i++){
			memset(book,0,sizeof(book));
			memset(cd,0,sizeof(cd));
			tot = 0;
			for(int j = i;j<=n;j++){
				int c = a[j];
				if(!book[c]){
					cd[++tot] = c;
					book[c] = true;
				}else{
					int id;
					for(int k = 1;k<=tot;k++){
						if(cd[k]==c){
							id = k;
							break;
						}
					}
					for(int k = id;k<=tot;k++){
						book[k] = false;
					}
					tot = id;
					cd[tot] = c;
					book[c] = true;
				}
			}
			for(int j = 1;j<=tot;j++){
				t[cd[j]]++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
