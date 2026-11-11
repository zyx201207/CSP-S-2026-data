#include<iostream>
#include<set>
using namespace std;
struct node{
	node* next;
	int x;
};
int ans[10000]={0},a[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	set<int> s;
	cin>>n>>m;
	node table[10000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;i++){
			table[i].x=a[i];
			table[i].next=&table[i+1];
		}
		for(int j=i;j<=n;j++){
			int old=s.size();
			s.insert(table[j].x);
			if(old==s.size()){
				int k=1;
				for(;k==table[j].x;k++){
					s.erase(k);
				}
				table[k].next=&table[j];
			}
		}
		for(int j=1;j<=s.size();j++){
			ans[table[j].x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
} 
