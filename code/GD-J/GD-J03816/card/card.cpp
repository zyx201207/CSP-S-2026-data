#include <bits/stdc++.h>
using namespace std;
int n,m,lenb;
int a[100005];
stack<int> b[100005];
int cnt[100005];
void sovle1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int x=1;x<=n;x++){
				if(a[j]==b[x]) flag=1;
			}if(flag){
				while(b.empty()){
					b.pop();
					lenb--;
				}
			}else {
				b.push_back(a[j]);
				lenb++;
			}
		}for(int j=1;j<=lenb;j++){
			cnt[b.pop()]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	sovle1();
}
