#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int num[200005];
int has[200005];
int cnt[200005];
void check(int s){
	
	if(s>n) return ;
	if(num[s]==s) cnt[a[s]]++,s++;
	else s=num[s];
	check(s);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[i]=i;
		
		if(has[a[i]]!=0){
			num[has[a[i]]]=i;
		}
		has[a[i]]=i;
		
	}
	for(int i=1;i<=n;i++){
		check(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
/*4 3
1 2 1 3*/
//Trick||Treat!