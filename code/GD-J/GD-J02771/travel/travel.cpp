#include <Bits/stdc++.h>
using namespace std;
char max_str(char x, char y){
	return x - '0' > y - '0' ? x : y;
}
char min_str(char x, char y){
	return x - '0' < y - '0' ? x : y;
}
int in_same_r(int ticket1_room, int ticket2_room, string ticket1_ID, string ticket2_ID){
	return (ticket1_room == ticket2_room) ? 1 : 0;
}
int max(int x, int y){
	return x > y ? x : y;
}
int min(int x, int y){
	return x < y ? x : y;
}
int in_same_p(int ticket1_room, int ticket2_room, string ticket1_ID, string ticket2_ID) {
	return (in_same_r(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) && (ticket1_ID[0] == ticket2_ID[0] && ticket1_ID[1] == ticket2_ID[1])) ? 1 : 0;
}
int in_same_c(int ticket1_room, int ticket2_room, string ticket1_ID, string ticket2_ID) {
	return (in_same_r(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) && in_same_p(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) && (
			(
				(ticket1_ID[2] == 'A' || ticket1_ID[2] == 'B' || ticket1_ID[2] == 'C') &&
				(ticket2_ID[2] == 'A' || ticket2_ID[2] == 'B' || ticket2_ID[2] == 'C')
			) || 
			(
				(ticket1_ID[2] == 'F' || ticket1_ID[2] == 'D') && 
				(ticket2_ID[2] == 'F' || ticket2_ID[2] == 'D')
			))
		) ? 1 : 0;
}
int rep(int ticket1_room, int ticket2_room, string ticket1_ID, string ticket2_ID){
	return (in_same_r(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) && in_same_p(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) && in_same_c(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID) &&
		(
			(max_str(ticket1_ID[2], ticket2_ID[2]) == max_str('A', 'B') && min_str(ticket1_ID[2], ticket2_ID[2]) == min_str('A', 'B')) ||
			(max_str(ticket1_ID[2], ticket2_ID[2]) == max_str('C', 'B') && min_str(ticket1_ID[2], ticket2_ID[2]) == min_str('C', 'B')) ||
			(max_str(ticket1_ID[2], ticket2_ID[2]) == max_str('D', 'F') && min_str(ticket1_ID[2], ticket2_ID[2]) == min_str('D', 'F'))
		)
	) ? 1 : 0;
}
int ANS_CLASS(string INPUT_FILE){
//	char InputFileName[INPUT_FILE.length()+1] = "";
//	for(int i = 0;i < INPUT_FILE.size(); i++){
//		InputFileName[i] = INPUT_FILE[i];
//	}
//	freopen(InputFileName, "r", stdin);
	
	int ticket1_room, ticket2_room;
	string ticket1_ID, ticket2_ID;
	cin >> ticket1_room >> ticket1_ID >> ticket2_room >> ticket2_ID;
	cout << in_same_r(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID);
	cout << in_same_p(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID);
	cout << in_same_c(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID);
	cout << rep(ticket1_room, ticket2_room, ticket1_ID, ticket2_ID);
	cout << endl;
	return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ANS_CLASS("travel.in");
//	ANS_CLASS("travel1.in");
//	ANS_CLASS("travel2.in");
//	ANS_CLASS("travel3.in");
//	ANS_CLASS("travel4.in");
//	ANS_CLASS("travel5.in");
	return 0;
}
