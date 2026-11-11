#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("card.in");
	ofstream out("card.out");
//
	int n,m;
	in>>n>>m;
	vector<int> deck(n),ans(m+1,0);
	for(int i=0;i<n;i++){
		in>>deck[i];
//		cout<<deck[i]<<' ';
	}
//	vector<bool> deck2(n);
	for(int i=0;i<n;i++){
		int table_l=0;
		vector<int> table(n-i,0),card(m+1,n+1);
		
//	vector<bool> new_deck2(n);
//	deck2=new_deck2;
		for(int j=i;j<n;j++){
			if(card[deck[j]]<table_l&&table[card[deck[j]]]==deck[j]){
				table_l=card[deck[j]]+1;
			}else{
				card[deck[j]]=table_l;
				table[table_l]=deck[j];
				table_l++;
			}
//			for(int k=0;k<table_l;k++){
//				cout<<table[k]<<' ';
//			}
//			cout<<endl;
//			for(int k=1;k<=m;k++){
//				cout<<card[k]<<' ';
//			}
//			cout<<endl;
		}
//		cout<<endl;
		for(int j=1;j<=m;j++){
			if(card[j]<table_l&&table[card[j]]==j){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		out<<ans[i]<<' ';
	}
	return 0;
} 
