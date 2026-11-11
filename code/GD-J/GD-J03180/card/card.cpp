#include <bits/stdc++.h> 
using namespace std;
const int N=5e5+1,M=3e5+1;
int b[M];
struct node{
	int id;
	int start;
	int end;
}a[N];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i].id;
		if(!a[a[i].id].start)a[a[i].id].start=i;
		a[a[i].id].end=i;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i=1+a[a[i].id].end){
			b[a[i].id]++;
		}
	}for(int i=1;i<=m;i++)cout <<b[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
