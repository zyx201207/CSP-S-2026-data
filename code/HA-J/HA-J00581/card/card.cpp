#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n,m;
int a[N];
int ans[N];

void game(int id){
	vector<int> ix(n+10, -1);
	//vector<int> fake(n+10, 0);
	//vector<bool> vis(m+10, false);
	
	//printf("==============> Game %d\n",id);
	for(int i = id; i <= n; i++){
		int cd = a[i];
		if(ix[cd] != -1){
			//fake[ix[cd]] += 1;
			//fake[i] -= 1;
			for(int j = ix[cd]; j < i; j++) ix[a[j]] = -1;
			//printf("Card ID%d~%d was wasted. (",ix[cd],i-1);
			//for(int j = ix[cd]; j < i; j++){
			//	printf("%d, ",a[j]);
			//}printf(")\n");
		}
		//printf("Card %d was pushed. (ID: %d)\n",cd,i);
		ix[cd] = i;
	}

	for(int i = id; i <= n; i++){
		if(ix[a[i]] == i){
			ans[a[i]]++;
			//printf("ans[%d]++; (in game %d)\n",a[i],id);
		}
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	
	scanf("%d%d",&n,&m);
	
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		game(i);
	}
	
	for(int i = 1; i <= m; i++){
		printf("%d ",ans[i]);
	}
	
	return 0;
}
