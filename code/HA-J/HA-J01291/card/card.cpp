#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];bool c;
void cardsplay(int r){
	for (int i = 1;i <= n;i++){
		b[i] = a[i];
		for (int j = 1;j < i;j++){
			if (c) b[j] = 0;
			if (j == b[j] && !c){
				c = 1;}}}}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	return 0;}
