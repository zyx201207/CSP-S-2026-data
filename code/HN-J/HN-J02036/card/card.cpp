#include<bits/stdc++.h>
using namespace std;
int s[100000],l = 0;
void push(int n){
	for(int i = 0;i < l;++i){
		if(s[i] == n){
			l = i;
			break;
		}
	}
	s[l] == n;
	l++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[300001];
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;++i){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < n;++i){
		l = 0;
		for(int j = i;j < n;++j){
			push(a[j]);
		}
		for(int j = 0;j < l;++j){
			b[s[j]]++;
		}
	}
	for(int i = 1;i <= m;++i){
		printf("%d ",b[i]);
	}
	return 0;
}
