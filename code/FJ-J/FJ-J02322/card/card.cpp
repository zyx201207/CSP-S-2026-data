#include <iostream>
#include <cstdio>
using namespace std;
int n,m,cardw;
int a[500005];
int cards[300005];
int table[500005];
int findcard(int i,int card){
	for(int j = 0;j < i;j ++){
		if(table[j] == card)
			return j;
	}
	return -1;
}
void play(int i){
	cardw = 0;
	for(int j = i;j < n;j ++){
		if(findcard(cardw,a[j]) == -1)
			table[cardw ++] = a[j];
		else
			cardw = findcard(cardw,a[j]) + 1;
	}
	for(int j = 0;j < cardw;j ++){
		cards[table[j]] ++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		play(i - 1);
	}
	for(int i = 1;i <= m;i ++){
		cout << cards[i];
		if(i != m)
			cout << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
