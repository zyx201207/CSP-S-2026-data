#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int mm[maxm];
int lll[maxn];
int n,m;
void game(int num){
	queue<int>k;
	for(int i=num;i<=n;i++){
		k.push(lll[i]); 
		//cout<<lll[i]<<' ';
	}
	int cnt=k.size();
	//cout<<endl;
	int s[maxn],top=0;
	for(int i=1;i<=cnt;i++){
		bool y=true;
		int ink;
		for(int j=1;j<=top;j++){
			if(k.front()==s[j]){
				y=false;
				ink=j;
			
			}
			
		}
		
		if(y)s[++top]=k.front();
		else {
			for(int p=ink-2;p<=top;p++){
				top--;
			}
			s[++top]=k.front();
		}
		//cout<<"ink="<<ink<<endl;
		//cout<<"top="<<top<<endl;
		
		//for(int u=1;u<=top;u++){
		//	cout<<s[u]<<' ';
			
		//}
	//	cout<<endl;
	
		k.pop();
	}
	for(int i=1;i<=top;i++){
	//	cout<<s[i]<<' ';
		mm[s[i]]++;
	}
	//cout<<endl<<endl<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		lll[i]=a;

	}
	for(int i=1;i<=n;i++){
		game(i);
	
	} 
	
	for(int i=1;i<=m;i++)cout<<mm[i]<<' ';
	return 0;
}//10 3 3 1 2 1 3 2 3 1 2 1
//
