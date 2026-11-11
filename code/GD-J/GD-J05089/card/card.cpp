#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	node* Next;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	
	int n; // 牌的数量&游戏的局数 
	int m; // 点数种类数
	cin >> n >> m;
	int x;
	cin >> x;
	
	node* head = new node;
	head->Next = NULL;
	head->id = x;
	
	node* t = head;
	for (int i=2; i<=n; i++){
		node* p = new node;
		cin >> p->id;
		p->Next = NULL;
		t->Next = p;
		t = t->Next;
	} // 输入桌面上从左到右牌的点数
	
	int cnt = 0; // jushu
	t = head;
	for (int i=1; i<=n; i++){
		// n局游戏
		int pai;
		for (int j=1; j<=i; j++){
			// 数打出的牌
			pai = j;
			t = head;
			bool flag = 0;
			// 找有没有打出的牌 
			while (t != NULL){
				if (t->id == pai){
					t->Next = NULL;
					flag = 1;
					break;
				}
				else{
					t = t->Next;
				}
			}
		
			if (!flag){
				t->id = pai;
				t->Next = NULL;
			}
			
			t = head;
			while (t != NULL){
				if (t->id == i){
					cnt++;
					break;
				}
				t = t->Next;
			}
		}
		cout << cnt << ' ';
		cnt = 0;
	} 
	
	return 0;
}
