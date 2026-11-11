#include<bits/stdc++.h>
using namespace std;
struct List{
	List* next;
	int val;
	List():next(NULL),val(){}
	List(int x):next(NULL),val(x){}
};
List* live=new List();
bool isLive(List* temp,int q){
	List* root=temp;
	while(root!=NULL){
		if(root->val==q) return true;
		root=root->next;
	}
	return false;
}
 
void game(vector<int> cards,int i){
	int j=i;
	while(j<cards.size()){
		List* temp=live;
		if(isLive(live,cards[j])){
			while(temp->next->val!=cards[j]){
				temp=temp->next;
			}
			temp->next=NULL;
		}else{
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new List(cards[j]);
		}
		
	}
	cout<<endl;
}
vector<int> num(int n,vector<int> cards,int m){
	vector<int> result(m,0);
	for(int p=0;p<n;p++){
		game(cards,p);
		List* temp=live;
    	while(temp!=NULL){
			result[temp->val]++;
		}
		live->next=NULL;
	}
	return result;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> cards(n);
	for(int i=0;i<n;i++) cin>>cards[i];
	vector<int> answer(m);
	answer=num(n,cards,m);
	for(int j=0;j<m;j++){
		cout<<answer[j]<<" ";
	}
	return 0;
}
