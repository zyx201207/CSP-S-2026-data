#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,m,a[N],table[N],book[N];
void clear_card(int x){
	for(int i=1;i<=x;i++){
		table[i]=0;
	}
}
bool has_two_card(int x){
	for(int i=1;i<=n;i++){
		if(table[i]==a[x]){
			clear_card(x-1);
			return 1;
		}
	}
	return 0;
}
void total_card(){
	for(int i=1;i<=n;i++){
		if(table[i]>0) book[table[i]]++;
	}
}
void to_the_right(){
	string s="";
	for(int i=1;i<=n;i++){
		if(table[i]>0) s+=(table[i]+'0');
	}
	memset(table,-1,n+1);
	for(int i=1;i<=n;i++) table[i]=(s[i-1]-'0');
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(table,-1,n+1);
		for(int j=i;j<=n;j++){
			table[i]=a[i];
			has_two_card(i);
		}
		total_card();
		to_the_right();
	}
	for(int i=1;i<=m;i++) cout<<book[i]<<" ";
	return 0;
}
