#include <bits/stdc++.h>
using namespace std;
struct lb{
	int next=0;
	int front =0;
	bool zai=false;
};
lb lianbiao[300005];
int you=0;
int a[500005],ans[300005];

void push(int j){
	int card = a[j];
	if(lianbiao[card].zai==false){
		lianbiao[card].next=0;
		lianbiao[card].front=you;
		lianbiao[you].next=card;
		you=card;
		lianbiao[card].zai=true;
	}else{
		for(int i = lianbiao[card].next;i!=0;i=lianbiao[i].next){
			lianbiao[i].zai=false;
		}
		lianbiao[card].next=0;
		you=card;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		
		for(int j = i;j <=n;j++){
			push(j);
		}for(int j = 1;j <= m;j++){
			ans[j]+=(int)lianbiao[j].zai;
			lianbiao[j].zai=false;
		}you=0;		
	}
	
	for(int i = 1 ;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
