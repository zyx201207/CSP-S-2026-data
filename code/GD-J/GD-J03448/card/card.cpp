#include<bits/stdc++.h>
using namespace std;
struct kard{
	string number;
}cards[500005];
string intTostring(int i){
	string ans="";
	while(i>0){
		char ch=i%10+'0';
		ans=ch+ans;
		i/=10;
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	map<string,int> card;
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> cards[i].number;
		card[cards[i].number]=0;
	}
	for(int i=0; i<n; i++){
		string now;
		for(int j=i; j<n; j++){
			if(now.find(cards[j].number)<now.size()){
				string s=cards[j].number+" ";
				now=now.substr(0,now.find(cards[j].number))+s;
			}
			else{
				now=now+cards[j].number+" ";
			}
//			cout << j << " number:" << cards[j].number << " now:" << now << endl;
		}
//		cout << endl << i << " " << now << endl << endl;
		string c="";
		for(int i=0; i<now.size(); i++){
			if("0" <= now.substr(i,1) && "9">=now.substr(i,1)){
				c+=now[i];
			}
			else{
				card[c]++;
				c="";
			}
		}
	}
//	for(auto it:card){
//		cout << it.first << " " << it.second << endl;
////		cout << it.second << " ";
//	}
	for(int i=1; i<=m; i++){
		printf("%d ",card[intTostring(i)]);
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
} 
