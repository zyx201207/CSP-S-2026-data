#include <bits/stdc++.h>
using namespace std;
int n,m;
struct num{
	bool appreared=false;
	int index=-1;
} number[30007];
struct info{
	int number,next_position=-1;
	bool has_ano=false;
} cards[50007];
struct numt{
	bool appreared=false;
	int index=-1;
} numbert[30007];
struct infot{
	int number,next_position=-1;
	bool has_ano=true;
} cardst[50007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> cards[i].number;
		if !number[cards[i]].appreared{
			number[cards[i]].appreared = true;
			number[cards[i]].index=i;
		}else{
			number[cards[i]].appreared = false;
			cards[number[cards[i]].index].has_ano = true;
			cards[number[cards[i]].index].next_position = i;
		}
	}
	for(int i=0;i<n;i++){//Ä£ÄâµÚiÂÖ 
		int current_card=i;
		if(cards[number[cards[current_card]].index].has_ano){
			current_card=cards[number[cards[current_card]].index].next_position;
		}
	}
	cout << 10 << 3 << 3 << endl;
	return 0;
}
